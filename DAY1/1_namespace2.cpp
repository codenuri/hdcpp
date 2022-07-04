#include <stdio.h>

// 8page
// namespace 의 멤버에 접근하는 3가지 기술

namespace Audio
{
	void init() { printf("Audio init\n"); }
}
namespace Video
{
	void init() { printf("Video init\n"); }
}

// global namespace : 어떠한 이름공간에도 포함되지 않은 공간
void init() { printf("global init\n"); }

// 아래 코드는 함수 안 또는 밖에 있을수 있습니다.
// 함수안 : 해당 함수 안에서만 적용
// 함수밖 : 선언 이후의 모든 함수에 적용
using Video::init; 

int main()
{
	// 1. 완전한 이름을 사용하는 방법(qualified name)
	Video::init();

	// 2. using declaration(선언) 사용
//	using Video::init;  // Video::init 는 "Video::" 없이 사용하게 해달라


	init(); // using 선언이 함수안이면  Video::init, 
			// using 선언이 함수밖이면  error
	::init(); // global      "::" scope resolution 연산자라고 합니다.


	// 3. using directive(지시어) 사용
	using namespace Video; // Video 이름공간 전체를 Video:: 없이 사용
	init();
	
}

