
// C++ 함수 특징 3. inline   .. 32page


       int add1(int a, int b) { return a + b; }
inline int add2(int a, int b) { return a + b; }

// 장점 : 빠르다.
// 단점 : 크기가 큰 함수를 여러번 치환하면 실행파일 크기가 커질수 있다.
//	

int main()
{
	int n1 = add1(1, 2); // 1. 인자 2개를 약속된 장소에 넣고
						 //    (32bit:스택, 64bit:레지스터)
						 // 2. 함수로 이동 (call add1)

	int n2 = add2(1, 2);  // 컴파일시 "add2 의 기계어 코드"를 이 위치에 치환해 달라
}
