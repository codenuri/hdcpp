#include <iostream>
#include <thread>
#include <future>
using namespace std::literals;

// std::async : 내부적으로 packaged_task 를 만들어서
//				std::thread 로 수행
//				사용자가 직접 "std::thread" 사용할필요없음.
//				join  도 필요 없으므로 편리
//				간단한 작업에 권장

// std::packaged_task : 사용자가 직접 std::thread 로 스레드생성
//						join()도 필요
//						여러개 스레드를 만들어서 std::vector등으로
//						관리하려면 이방식!



int add(int a, int b)
{
	std::this_thread::sleep_for(2s);
	return a + b;
}

int main()
{
//	int r1 = add(1, 2); // 주스레드가 실행

	std::future<int> ft = std::async(&add, 1, 2); // 새로운 스레드로 즉시실행
								
	std::cout << "continue main\n";

	int ret = ft.get();

	std::cout << "result : " << ret << std::endl;;
}





// std::async : "return 값" 형식의 함수를 즉시 스레드로 실행
//              내부적으로는 다시 std::thread 사용해서 생성
//              주로 "스레드 풀"로 구현
// 
// ==> 아래 방법은 모두 "std::thread" 사용
// packaged_task : "return 값" 으로 된 함수를 보관했다가
//                 std::thread 로 실행해서 결과 얻기
//----------------------------------------
// promise / future : 결과를 얻기 위한 도구
//----------------------------------------
// std::thread : C++에서 스레드를 만드는 클래스
//-----------------------------------------
// OS : CreateThread(), pthread_create()