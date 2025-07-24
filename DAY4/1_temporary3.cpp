#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
};

// 임시객체와 함수 인자 #2

// 함수 인자로
// const T& : 읽기만 하겠다는 의도
//			  => temporary 받을수 있다.
//       T& : 읽기/쓰기 모두 하겠다는 의도
//			  => temporary 받을수 없다.
void init(Point& pt) { pt.x = 0; pt.y = 0; }

int main()
{
	Point pt{1, 2};

	init(pt); // ok

	init( Point{1,1} ); // 되는게 좋을까요 ? 안되는게 좋을까요 ?
						// 안되야 합니다.
						// 그래서 이코드는 에러.
	

	std::cout << "-----" << std::endl;
}





// github.com/codenuri/hdpp 에서

// DAY4.zip 받으시면 됩니다.