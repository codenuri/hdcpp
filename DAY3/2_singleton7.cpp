#include <iostream>
#include <mutex>


class Singleton
{
private:
	Singleton() {}

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;	

	inline static std::mutex m;
	inline static Singleton* sinstance = nullptr;
public:

	static Singleton& get_instance()
	{ 
		std::lock_guard<std::mutex> g(m);

		if ( sinstance == nullptr )
			sinstance = new Singleton;

		return *sinstance;
	} 
};

// Mouse 도 위와 동일한 싱글톤 기술로 하고 싶다
class Mouse : public Singleton
{

};

int main()
{
	Mouse& m1 = Mouse::get_instance();


}



