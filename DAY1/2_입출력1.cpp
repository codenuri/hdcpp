#include <cstdio>	// printf, scanf
#include <iostream> // std::cout, std::cin

int main()
{
	int n = 10;

	// C style 입출력
	printf("n = %d\n", n); // C style
//	scanf("%d", &n);	   // 입력
	scanf_s("%d", &n);		// 보안 강화 버전

	// C++ style
	// 특징 : %d, %f 등의 서식 문자열을 표기할 필요 없습니다.
	// 정체 : printf 는 함수,
	//       std::cout 은 객체(금요일날 자세히), 지금은 사용법만 알아두세요

	std::cout << "n = " << n << std::endl;// std::endl 은 개행("\n")의미

	// C++ 표준 입력
	// 특징 :	1. %d 등의 서식 문자열 필요 없음
	//			2. &n 이 아니라 n 을 전달
	//       
	std::cin >> n;


	// 그런데, cout 이 printf 보다 좀 느립니다.
	// 그래서 "출력 속도"가 중요시 되면 "printf" 를 사용하는것이 좋습니다.
	// C++23 부터는 빠른 cout도 제공될 예정입니다.
}




