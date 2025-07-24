// cmp1, cmp2, Less, Greater 모두 복사해오세요

template<typename T> void Sort(T cmp)
{
	bool b = cmp(1, 2);
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
// 1. 생성된 Sort() 함수 갯수는 ?
// 2. 각 Sort() 함수에서 인라인 치환 여부는 ?
// 3. Sort()를 제외한 나머지 함수의 갯수는 ?