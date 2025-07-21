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
	Dog* p1 = &d; // ok
//	int* p2 = &d; // error

	// 핵심 #1. 기반 클래스 포인터로 파생 클래스 주소를 담을 수있다.
	// => "upcasting" 이라고 합니다.
	// => 가능한 이유는 메모리 그림 참고
	Animal* p3 = &d; // ok

	// 핵심 #2. 컴파일러가 p3 가 실제 가리키는 객체가 어떤 종류인지 알수 없다.
	// => 오직, p3 자체의 타입만 알수 있다.
	// => 아래 코드를 생각해 보세요
//	if ( 사용자 입력 == 1) p3 = new Animal;

	// 핵심 #3. 기반 클래스 포인터로는 파생 클래스가 추가한 멤버에 접근할수없다.
	// => p3 로는 Animal 멤버만 접근 가능하다.
	// => 이유 : 컴파일러가 p3가 가리키는 곳이 Dog 인지 확신할수 없다.	

	// static type check : 컴파일 시간에 타입이 맞는지 확인
	//						=> C++, C#, Java
	//  dynamic type check : 실행 시간에 타입이 맞는지 확인
	//						=> Python

	p3->age = 10;   // ok
	p3->color = 10; // error.


	// #4. p3 가 가리키는 곳에 Dog 가 있다는 확신이 있다면
	// => 개발자가 Dog* 타입으로 캐스팅해서 접근하면 됩니다.
	// => 단 반드시 Dog 라는 확신이 있을때 만 사용해야 합니다.
	// => p3 가 가리키는 곳이 Dog 가 아니라면
	// => A 부분에서 runtime error 발생할수 있습니다.
	Dog* pdog = static_cast<Dog*>(p3);

	pdog->color = 10; // ok <=== A


	// #5. 조사할수 없나요 ?
	// => 가능합니다.
	// => 1_upcasting1-1.cpp 추가 

}











