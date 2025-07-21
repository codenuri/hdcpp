#include <iostream> // <== 추가

class Animal
{
public:
	int age;
};
class Dog : public Animal
{
public:
	int color;
};
// 7 page
int main()
{
	Dog d;
	Animal a;

//	Animal* p3 = &d; 
	Animal* p3 = &a;  // p3 는 이제 Animal 객체를 가리킵니다.

	Dog* pdog = static_cast<Dog*>(p3);

	std::cout << pdog << std::endl;

}











