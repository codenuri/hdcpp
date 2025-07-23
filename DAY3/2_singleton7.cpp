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




int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();


}



