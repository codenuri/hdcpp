// C++ 에서 inline 함수의 의미
// #1. 함수 호출시 "call" 이 아니라 기계어 코드를 치환해달라
//     => inline 함수는 반드시 헤더 파일에 놓아야 합니다.
//     => 그럼, 여러개 소스에서 include 하면 구현이 2개이상 중복되지 않나요?

// #2. multiple definition 을 허용해 달라.
//     => ODR 예외(one definition rule)
//     => 단, 실행파일에는 한개의 정의만 있습니다.

// C static 일반함수 : 3개의 소스에서 include 해서 사용하면
//                   => 최종 실행파일에 3개가 있습니다.
//					 => 어셈블리에는 모두 다른 함수이름  
//					 => internal linkage

// C++ inline : 최종 실행파일에 한개만
//				=> external linkage

// C++17 이후 전역변수 앞에도 inline 가능
int g1; // 헤더에 놓으면 안됩니다. 여러파일 inlcude 시 에러
inline int g2; // 헤더에 놓아도 됩니다. 여러파일 inlcude 시 에러 아님
				// 최종 실행파일에는 한개
static int g3;	// 헤더 ok. 최종 실행파일 여러개			

// 확인하는 법. 여러 파일에서 include 시 "주소출력"해 보세요

inline 
int add(int a, int b)
{
	return a + b;
}

int main()
{
	int ret = add(1,2);
}