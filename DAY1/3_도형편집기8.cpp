#include <iostream>
#include <vector>

// #7. 디자인 패턴이란 ?
// => 1994 년에 발간된 책의 제목
// => 4명의 저자가 집필한 서적
// => 당시유명한 오픈소스를 분석해서 공통의 사용되는 코딩기법에 이름을 부여한것
// => 23개 이름. 
// => 4명의 저자가 다른 소스의 기술을 훔쳐서 책을 집필했다는 의미로
//    4명의 갱단(Gang's Of Four) 라고 합니다. "Gof 의 디자인 패턴"

// #8. prototype 패턴 
// => 견본이 되는 객체를 만들고 복사를 통해서 객체 생성
// => clone(), copy() 등의 이름을 가지는 함수가 이 패턴
// => 수요일오전에 제대로.

// #9. 리팩토링 용어 입니다. 의미를 이해해 보세요
// "replace conditional with polymorphism"
// => 코드에 제어문(if)이 있으면 OCP 를 만족할수 없다. 도형편집기4.cpp
// => 다형성(가상함수)로 변경하는 것을 고려해라        도형편집기5.cpp
//													(draw 가상함수도입)


class Shape 
{
	int color = 0;
public:
	virtual ~Shape() {}

	void set_color(int c) { color = c;}
	virtual int get_area() {return 0;}

	virtual void draw() { std::cout << "draw Shape\n"; }
	

	// 자신의 복사본을 생성하는 가상함수는 아주 유용하게 사용됩니다.
	virtual Shape* clone()
	{
		return new Shape(*this); // 자신(*this) 를 복사해서 생성
	}

};






class Rect : public Shape
{
public:
	void draw() { std::cout << "draw rect\n"; }

	// 참고 :가상함수 override 시 반환 타입 변경 가능합니다.(단, 상속관계타입만)
	virtual Rect* clone()
	{
		return new Rect(*this); 
	}	
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "draw circle\n"; }

	virtual Circle* clone()
	{
		return new Circle(*this); 
	}	
};

int main()
{
	std::vector<Shape*> v; 

	while( true )
	{
		int cmd;
		std::cin >> cmd;

		if      ( cmd == 1 ) v.push_back( new Rect);
		else if ( cmd == 2 ) v.push_back( new Circle);
		else if ( cmd == 9 )
		{
			for ( auto s : v)
			{
				s->draw(); 

			}
		}
		else if (cmd == 8 )
		{
			std::cout << "몇번째 도형을 복제할까요 >> ";

			int k;
			std::cin >> k;

			// 이제 조사할 필요없이 요청하면 됩니다.
			v.push_back( v[k]->clone() );

			// 자바같은 언어 에서 이런 개념을 아래와 같이 표현합니다. 의미 생각해보세요
			// "Don't Ask Do It"
	
		}
	}
}


