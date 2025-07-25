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
	// => 객체를 만들어서 전달하지 말고, 
	//    객체를 만들기 위한 생성자 인자(x, y 값)을 전달하자.
	// vector가 내부적으로
	// 자신의 버퍼에 "new Point{1,2}" 로 Point 생성해서 보관

	v.emplace_back(1, 2); // 1. vector 버퍼에 Point 생성 - 생성자
						  // 2. "-------------"
						  // 3. Point 소멸자


	std::cout << "-----" << std::endl;
}

// main				  emplace_back			    Point(int x, int y)
// new Point(1,2)    =================================> 
// emplace_back(1,2) ====> 1, 2 도착
//					       인자를 다시 생성자로 전달 ===>  	

// vector<int>
// => 그냥 push_back 하세요.
// => int 는 생성자 개념 없음
// => empalce_back 도 가능(동일 성능). 단, 가독성이 push_back 선호가 많음

// vector<Point*>
// => 그냥 push_back,  값이 아닌 주소 보관

// vector<Point>
// => emplace_back 이 push_back 보다좋음

// push_back ==> emplace_back
// push_front ==> emplace_front
// insert     ==> emplace
