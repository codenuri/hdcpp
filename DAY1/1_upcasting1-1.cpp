#include <iostream> // <== 추가

class Animal
{
public:
	int age;
	virtual ~Animal() {}  // 이제 Animal 에는 가상함수가 있고
						  // Animal 의 모든 파생클래스 객체는 가상함수 테이블생성
						  // 테이블에 타입정보 추가
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

	// static_cast : 컴파일 시간 캐스팅
	//               컴파일러는 컴파일 시간에 p3 가 가리키는 곳이 어떤객체인지
	//			     알수없습니다.
	//               그래서 아래 코드는 항상 성공, 주소가 나옵니다.
	//               만약 실제 객체가 Dog 가 아니었다면 버그
	//				"사용자 책임"

	// Dog* pdog = static_cast<Dog*>(p3);


	// dynamic_cast : 실행시간 캐스팅
	//				  실행시간에 p3가 가리키는 곳이 Dog 라면 캐스팅 허용
	//				  Dog 가 아닌경우, 0 반환
	//               단, 조사하려면 메모리에 추가 정보가 있어야 한다.
	//				 => C++ 은 타입 정보를 "가상함수테이블"에 보관
	//				 => 따라서, 가상함수가 한개 이상 있는 타입만 dynamic_cast가능
	Dog* pdog = dynamic_cast<Dog*>(p3);

	std::cout << pdog << std::endl;

}











