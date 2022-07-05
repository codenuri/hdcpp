// 8_반복문 38 page
#include <iostream>

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	for (int i = 0; i < 10; i++)
		std::cout << x[i] << std::endl;


	// C++11 에서 새로운 for 문이 제공됩니다. - "range-for"라고합니다.
	// Python : for e in x:
	// C#	  : foreach e in x
	
//	for (int n : x)  // x자리는 배열뿐 아니라 C++표준의 list등도 가능
	for (auto n : x)
	{
		std::cout << n << std::endl;
	}

	// 일부만 출력할수 있나요 ?
	// 한개씩 증가가 아니라 2개씩 증가 할수 있나요 ?
	// 거꾸로 출력(파이썬의 reversed) 할수 없나요 ?
	// ==> C++20 부터 지원됩니다.
	// ==> 그전에는 그냥 "예전 for문" 사용하세요.

	// 성능은 어떤가요 ?
	// => 예전 for 문과 동일합니다. 
}
