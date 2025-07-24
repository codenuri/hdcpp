#include <iostream>
#include <vector>

// move6

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy" << std::endl; }
	Object(Object&&)      { std::cout << "move" << std::endl;	}
};
int main()
{
	const Object o1;
	Object o2 = std::move(o1);	 // move 아닌 copy
			//  static_cast<o1의 타입&&>(o1)
			//  static_cast<const Object&&>(o1)

	// 핵심 : 상수객체는 MOVE 될수 없다.
	//		  std::move() 사용시 복사 생성자 호출
}



