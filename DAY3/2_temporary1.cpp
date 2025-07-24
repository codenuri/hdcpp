#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl;	}
};
int main()
{
//	Point pt(1, 2); // named object
					// 수명 : {}을 벗어날때 파괴


//	Point(1, 2);	// unnamed object
					// 수명 : 자신을 선언한 문장의 끝(;)

//	Point(1,2), std::cout << "X\n";
	Point{1,2}, std::cout << "X\n";

	std::cout << "-------" << std::endl;
}





