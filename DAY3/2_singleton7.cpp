#include <iostream>
#include <mutex>


class Cursor
{
private:
	Cursor() {}

	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;	

	inline static std::mutex m;
	inline static Cursor* sinstance = nullptr;
public:

	static Cursor& get_instance()
	{ 
		std::lock_guard<std::mutex> g(m);

		if ( sinstance == nullptr )
			sinstance = new Cursor;

		return *sinstance;
	} 

};

// Mouse 도 위와 동일한 싱글톤기술로 하고 싶다
class Mouse 
{

};

int main()
{
	Mouse& m1 = Mouse::get_instance();


}



