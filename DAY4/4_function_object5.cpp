#include <iostream>
#include <vector>
#include <algorithm>

// 아래 Sort 는 비교 정책을 인자로 받기 때문에
// 장점 : 유연성이 있습니다.
// 단점 : 2중루프 안에서 비교 함수 호출 - 느립니다.

// C언어 qsort()가 이방식인데..
// => 데이타가 많을때는 사용하지 마세요 - 느립니다.

// "정책 교체가 가능한데, 빠르게 할수 없을까요 ?"
// => 함수객체는 가능
// => 다음예제

void Sort(int* x, int sz , bool(*cmp)(int, int) )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
//			if (x[i] > x[j])				// 1

			if ( cmp(x[i], x[j]) == true )	// 2
				std::swap(x[i], x[j]);
		}
	}
}
//---------------------------------
inline bool cmp1(int a, int b) { return a < b;}
inline bool cmp2(int a, int b) { return a > b;}

int main()
{
	int x[] = { 1,3,5,7,9,2,4,6,8,10 };

	Sort(x, 10, cmp1);
	Sort(x, 10, cmp2);
}

