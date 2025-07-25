#include <functional>

void foo(int a) {}

class Sample 
{
public:	
	void goo(int a) {}
};

int main()
{
	void(*f1)(int) = &foo;
	void(*f2)(int) = &Sample::goo;
}
