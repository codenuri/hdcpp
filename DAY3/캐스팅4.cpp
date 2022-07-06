int main()
{
	const int c = 10;

	int* p1 = (int*)&c;				// ok
	int* p2 = static_cast<int*>(&c);// error
	int* p3 = reinterpret_cast<int*>(&c);// error
				// => 서로 다른 타입의 주소변환은 가능하지만
				// => 상수성을 제거하는 캐스팅은 안됨

	int* p4 = const_cast<int*>(&c);
				// => 동일 타입의(참조, 주소의) 상수성을 제거하는 캐스팅

}
// static_cast : 안전한 경우만 허용. 일반적인 프로그램이라면 이것만 사용하는것이 좋다
// reinterpret_cast : 서로 다른 타입의 주소 변환
// const_cast       : 상수성 제거
// dynamic_cast     : RTTI, 상속을 알아야 합니다.
