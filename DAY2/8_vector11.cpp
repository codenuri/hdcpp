#include <iostream>

// C 언어는 "동적배열", "list", "tree" 등이 필요하면 
// => 직접 만들어야 합니다..
// => 완벽히 라이브러리로 구축하기는 어렵습니다.

// C++ 언어는, 대부분의 자료구조가 "타입화" 되어 있습니다.
#include <vector>
#include <list>

int main()
{
	int n = 0;
	std::vector<int> v; // 크기가 0인 vector. 아직 메모리 할당 안됨.

	while (1)
	{
		std::cin >> n;

		if (n == -1)
			break;
		
	//	v[0] = n; // runtime error. 아직 v는 크기 없습니다.

		v.push_back(n); // 끝에 한개 추가(크기가 자동 증가)
	}

	std::cout << "입력된 갯수    : " << v.size() << std::endl;

	/*
	for (int i = 0; i < count; i++)
	{
		std::cout << v[i] << std::endl;
	}
	*/

	for (auto e : v)
		std::cout << e << ", ";
}
// 실행후 "몇개 입력하고", "-1" 입력해 보세요
