#include <iostream>
#include <vector>

class Point
{
	int x, y;
public:
	Point(int a, int b)	{ std::cout << "Point()" << std::endl;	}
	~Point()            { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "copy ctor" << std::endl; }
	Point(Point&&)      { std::cout << "move ctor" << std::endl; }
};

int main()
{
	std::vector<Point> v;
	
	// vector에 요소 넣는 방법 
	
	// #1. 객체를 생성후 push_back 으로전달. 
//	Point pt{1, 2};		// 1. Point 생성자 호출	
//	v.push_back(pt);	// 2. Point 복사 생성자 호출
//	v.push_back(std::move(pt)); // 2. Point 이동(move) 생성자 호출
						// 3. "----------------" 출력 - main 마지막줄
						// 4. pt 소멸자
						// 5. vector 안에 보관중인 Point 객체 파괴-소멸자

	// #2. 임시객체 형태로 vector에 넣기(전달)	
//	v.push_back(Point{1,2}); // 1. 임시객체 생성자
							 // 2. 이동생성자 - 버퍼안에 복사본 생성시
							 // 3. 임시객체 소멸자
							 // 4. "--------------------"
							 // 5. vector 파괴시, 버퍼의 Point 객체파괴-소멸자

	// #3. push_back 이 아닌 emplace_back 사용 
	// => 완벽한 기술로 만든 함수 


	std::cout << "-----" << std::endl;
}

