// 6_vector1
#include <iostream>

int main()
{
	// 1. 사용자 에게 2개의 정수를 입력 받고 싶습니다.
	//    그런데 입력된 값은 나중에 사용하기 위해 반드시 보관되어야 합니다
	// => 2개의 정수형 변수가 필요 하다.

	int n1;
	int n2;
	
	std::cin >> n1;
	std::cin >> n2;


	// 2. 이번에는 5개를 입력 받고 싶습니다. 
	// int a, b, c, d, e;	// 5개의 메모리에 이름이 모두 다르다.
							// 반복문에서 사용할수 없다.

	int x[5]; // 5개의 메모리를 "한개의 이름 + 인덱스"로 접근
			  // 반복문 사용가능

	// std::cin 을 5번 사용해야 하는데. 
	// 반복문을 사용할수 없을까 ?
	for (int i = 0; i < 5; i++)
	{
		std::cin >> x[i];
	}
}