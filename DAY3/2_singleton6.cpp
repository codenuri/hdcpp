#include <iostream>
#include <mutex>

// RAII 패턴
// => 자원 해지는 함수의 마지막 부분에서 하면 안된다. => 안전하지 않다.
// => 생성자/소멸자에 의존해라!

// Resource Acquision Is Initialization => C++ Idioms
// 자원의 획득은 (자원관리 객체가) 초기화 될때(생성자) 이다.

// => 자원의 해지가 아닌 "획득"에 포커스를 맞추어서 만든 용어
// => 생성자에서 획득후 소멸자 해지는 "당연한것" 아니냐!!
// => 그래서 "획득" 부분을 강조


template<typename T>
class lock_guard 
{
	T& mtx;
public:	
	lock_guard(T& m) : mtx(m) { mtx.lock();}
	~lock_guard()             { mtx.unlock();}
};



class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;	

	inline static std::mutex m;
	inline static Cursor* sinstance = nullptr;
public:
/*
	static Cursor& get_instance()
	{ 
		m.lock();

		if ( sinstance == nullptr )
			sinstance = new Cursor;

		// 여기서 예외가 발생하거나
		// if(실패) return ; // 나중에 이런 실수를 하면
						     // 아래 문장은 실행될수 없다.
		m.unlock();

		return *sinstance;
	}
*/

	static Cursor& get_instance()
	{ 
		{
			std::lock_guard<std::mutex> g(m);
//			lock_guard<std::mutex> g(m); // 1. g의 생성자에서 m.lock()
										// 2. g 파괴시 소멸자에서 unlock
										// 3. "A" 같은 코드가 있어도 g는
										//    안전하게 파괴
										// 4. 예외가 발생해도 지역변수는
										//    안전하게 파괴 됨을 보장
										// => 즉, 대부분의 모든 경우에 unlock보장
										// 5. 함수 종료전에 unlock 하려면
										// {} 사용
										// => 동기화 구간이 들여쓰기 되므로
										//    좋은 코드

			if ( sinstance == nullptr )
				sinstance = new Cursor;

			// 여기서 예외가 발생하거나
			// if(실패) return ; // A
		} // <== 이 순간 m.unlock()


		return *sinstance;
	}

};




int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();


}



