// 10 page 내용입니다.

//#include <stdio.h> // printf 에 전역공간에만 있다, 
				   // std::printf 는 에러!

#include <cstdio>	// C++ 언어가 다시 만든 헤더..
					// printf 가 전역에도 있고(C와 호환성을 위해)
					// std::printf 도 제공.

// C 헤더			C++ 헤더
// <xxx.h>		=>	<cxxx>		=> 앞에 c 추가, .h 는 제거
// <stdlib.h>	=>  <cstdlib>
// <string.h>	=>  <cstring>
// <math.h>		=>  <cmath>

int main()
{
	// printf 는 C 표준이지만, C++ 표준이기도 합니다.
	printf("hello\n"); // ok

	std::printf("hello\n"); // ??
}
