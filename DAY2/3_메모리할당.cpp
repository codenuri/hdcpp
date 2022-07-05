// 2_메모리할당 - 52 page
#include <iostream>
#include <cstdlib> // malloc/free

int main()
{
	// C 스타일
	int* p = (int*)malloc(sizeof(int) * 20);
	free(p);

	// C++ 스타일
	int* p1 = new int; 
	delete p1;

	int* p2 = new int[10];	// 배열형태로 할당하면
	delete[] p2;			// 꼭 배열 형태로 delete 해야 합니다.

	int* p3 = new int;
	free(p3);	// 이렇게 하면 안됩니다. malloc 은 free
				//					  new 는 delete 로!
}
// 52page 내용
//				malloc					new
// 정체			함수						키워드(연산자)
// 인자			크기(정수)				타입
// 반환타입		void*(대부분 캐스팅후사용)	인자로 전달한 타입*(캐스팅필요없음)
// 결정적차이		생성자 호출 안됨			생성자 호출 가능