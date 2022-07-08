// 4_STL_컨테이너1.cpp
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	v.resize(3); // 어떻게 만들었을까요 ? ( 크기가 줄어드는 경우 입니다.)
				 // 메모리 자체는 줄어들지 않습니다.(capacity : 5)
				 // size 변수만 줄이게 됩니다.(size : 3)

	std::cout << v.size() << std::endl;		// 3
	std::cout << v.capacity() << std::endl; // 5	

	v.push_back(7); // 끝에 한개(값7) 추가
					// 현재 상태는 capacity > size 이므로
					// 이 함수의 성능은 느리지 않습니다.(not expensive)

	std::cout << v.size() << std::endl;		// 4
	std::cout << v.capacity() << std::endl; // 5	

	v.shrink_to_fit();	// 여분의 메모리를 제거해달라.
						// "4개 크기 메모리 재할당후 기존 버퍼 복사"해서 사용


	std::cout << v.size() << std::endl;		// 4
	std::cout << v.capacity() << std::endl; // 4

	v.push_back(7); // 현재 상태는 capacity == size 이므로
					// 여분의 공간이 없습니다.
					// 그래서 이 연산은 메모리 재할당이 요구 됩니다.
					// expensive 한 연산 입니다.

	std::cout << v.size() << std::endl;		// 5
	std::cout << v.capacity() << std::endl; // 6(vc는 기존메모리크기 * 1.5배)
											// 8(g++ 은 2배)
											// 컴파일러마다 다릅니다.

	v.push_back(7);

}