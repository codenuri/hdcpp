#include <iostream>
#include <mutex>

// thread - safe 하게

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
		m.lock();
		if ( sinstance == nullptr )
			sinstance = new Cursor;
		m.unlock();

		return *sinstance;
	}
};


int main()
{
	Cursor& c1 = Cursor::get_instance();
	Cursor& c2 = Cursor::get_instance();


}



