#include <iostream>
#include <string>

// 예외 전용타입을 설계해서 사용하는것이 원칙 입니다.

class file_not_found
{
	std::string file_name;
	int mode;	// read/write 등..
public:
	file_not_found(const std::string& s) : file_name(s) {}

	// 이외에 실패에 대해서 다양한 정보를 전달할수 있도록 설계
};

// 아래처럼 비어 있는 클래스도 좋습니다.
// 클래스 이름 자체가 좋은 설명입니다.
class stack_overflow { };
class disconnect_wifi { };

int f1()
{
	if (1) throw file_not_found("a.txt"); // 임시객체 생성하는 모양으로 전달
	if (2) throw stack_overflow();
	if (3) throw disconnect_wifi();

	return 100;
}
int main()
{
	try
	{
		int ret = f1();
	}
	catch (file_not_found& e)
	{
		std::cout << "예외 발생" << std::endl;
	}
	catch (stack_overflow& e)
	{
	}
	catch (...) // 위에서 처리되지 않은 모든 예외 처리
	{
	}

	std::cout << "main 계속 실행" << std::endl;
}
