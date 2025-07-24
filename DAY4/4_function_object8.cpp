// cmp1, cmp2, Less, Greater 모두 복사해오세요
inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

struct Less { inline bool operator()(int a, int b) const { return a < b; } };
struct Greater { inline bool operator()(int a, int b) const { return a > b; } };



template<typename T> void Sort(T cmp)
{
	bool b = cmp(1, 2);  // "A"
}
int main()
{
	Less f1;
	Greater f2;

	Sort(cmp1);
	Sort(cmp2);
	Sort(f1);
	Sort(f2);
}
// 1. 생성된 Sort() 함수 갯수는 ?  3 개
// 2. 각 Sort() 함수에서 "A" 부분 인라인 치환 여부는 ?
// 3. Sort()를 제외한 나머지 함수의 갯수는 ?

// godbolt.org 의 왼쪽 창에 이 코드 넣으세요
