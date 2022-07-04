// 교재 5page 아래.. 파일 확장자 이야기
// 2_namespace.cpp - 교재 7 page
#include <stdio.h>

// 핵심 1. 프로그램의 다양한 구성 요소를 논리적으로 분할 할수 있다.
//     2. 이름 충돌등을 막을수 있다.

namespace Audio
{
	void init() { printf("Audio init\n"); }
}
namespace Video
{
	void init() { printf("Video init\n"); }
	
	// 이 안에 함수/구조체/전역변수등..
	// 모든 Video 관련 코드를  여기에 작성 합니다.
}
int main()
{
	Video::init();
	Audio::init();
}

