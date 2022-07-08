#include <iostream>

int f1()
{
	if (1)			
		throw 1;	

	return 100;
}

int main()
{
	// 예외 가능성이 있는 함수를 호출시, 
	// 1. try 블럭 안에서 함수를 호출해야 하고
	// 2. catch 로 잡아야 합니다
	try
	{
		int ret = f1();
		
		// f1 성공시 코드 작성
	}
	catch (int n)
	{
		std::cout << "예외 발생" << std::endl;
		// 1. 오류를 해결할수 없다면, 여기서 std::exit(-1) 등으로 
		//    프로그램 종료 시키세요
		// 2. 종료하는 코드 없으면 프로그램은 계속 실행됩니다.
	}
	std::cout << "main 계속 실행" << std::endl;
}
