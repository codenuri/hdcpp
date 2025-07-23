#include <iostream>
#include <mutex>

// DCLP 개념 과 문제점

class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;	

	inline static std::mutex m;
	inline static Cursor* sinstance = nullptr;
public:

	// 아래 함수가 100번 호출 될때를 생각해 보세요
	// 최초 호출      : 객체 생성
	// 이후 99번 호출 : 생성된 객체의 반환만 
	//					하지만 lock/unlock 을 수행하게 됩니다.
	/*
	static Cursor& get_instance()
	{
		m.lock();
		if ( sinstance == nullptr )
			sinstance = new Cursor;
		m.unlock();

		return *sinstance;
	}
	*/
	// 해결책 : 2번의 if 문
	// 최초 호출 : 2번의 if 문 실행 하므로 오버헤드(if 문 한번더 수행하므로)
	// 이후 호출 : lock/unlock 을 수행하지 않습니다. 빨라집니다.

	// DCLP(Double Check Locking Pattern) 이라고 합니다
	// => 1990 ~ 2000년대 초반 오픈소스에서 유행하던 기술
	// => 2004 년 "C++에서 DCLP 은 버그이다." 라는 논문 발표
	// => (scott mayer 가 안드레이 가 쓴 논문)

	// 결론 
	// #1. DCLP 를 사용하려면 reordering 을 막아야 합니다 - 금요일 설명
	// #2. 성능이 정말 중요한것 아니면 DCLP 를 사용하지 마세요

	static Cursor& get_instance()
	{
		if ( sinstance == nullptr )
		{
			m.lock();

			if ( sinstance == nullptr )
			{
				sinstance = new Cursor; // A

				// A 부분의 원리
				// 1. Cursor 생성 : temp = malloc(sizeof(Cursor))
				// 2. Cursor 생성자 호출
				// 3. (1)에서 생성된 객체 주소를 sinstance 에 넣기
				//		sinstance = temp;

				// 2와 3의 순서를 변경하면 temp 가 없어도 됩니다.

				// 1. Cursor 생성 : sinstance = malloc(sizeof(Cursor))
				// 3. (1)에서 생성된 객체 주소를 sinstance 에 넣기
				//		=> 이제 이코드 필요 없습니다
				// 2. Cursor 생성자 호출

			}

			m.unlock();
		}

		return *sinstance;
	}

};


int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();


}



