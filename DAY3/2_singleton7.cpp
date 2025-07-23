#include <iostream>
#include <mutex>

// CRTP ( Curiously Recurring Template Pattern )
// => 기반 클래스 만들때 파생 클래스 이름을 사용하게 하는 패턴
// => 원리 : 템플릿 인자로 파생 클래스 이름을 받는것

// 아래 코드가 "안드로이드 OS" 가 예전에 사용하던 코드
// github.com/aosp-mirror 접속

// platform system core  리포지토리

// libutils/include/utils/singleton.h 에 있는 코드



template<typename T>
class Singleton
{
protected:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;	

	inline static std::mutex m;
	inline static T* sinstance = nullptr;
public:

	static T& get_instance()
	{ 
		std::lock_guard<std::mutex> g(m);

		if ( sinstance == nullptr )
			sinstance = new T;

		return *sinstance;
	} 
};

// Mouse 도 위와 동일한 싱글톤 기술로 하고 싶다
class Mouse : public Singleton< Mouse >
{

};

int main()
{
	Mouse& m1 = Mouse::get_instance();


}



