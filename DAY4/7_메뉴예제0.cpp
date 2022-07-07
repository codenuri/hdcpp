#include <iostream>

// C 언어(절차적 언어)에서 프로그램이란 ?
// => main 함수의 1번째 줄부터 순차적으로 실행되는 실행흐름이다.
// => 실행흐름을 변경하려면 제어문
// => 실행흐름을 반복하려면 반복문
// => 프로그램을 기능별로 분리하려면 함수 를 사용한다.

int main()
{
	printf("1. 김밥\n");
	printf("2. 라면\n");
	printf("3. 우동\n");
	printf("메뉴를 선택 하세요 >> ");

	int cmd;
	scanf_s("%d", &cmd);

	switch (cmd)
	{
	case 1: break;
	case 2: break;
	case 3: break;
	}	
}
