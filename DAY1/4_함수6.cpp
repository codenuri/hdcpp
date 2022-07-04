
// 4_함수6. 후위 반환 타입 - 37page

//int square(int a)			// 일반적인 함수의 모양
auto square(int a) -> int	// C++11 에서 새로나온 함수 모양
{							// 후위 반환타입(suffix return type)
	return a * a;
}
int main()
{
	square(3);
}

// 파이썬도 타입 표기 가능합니다.(annotation 문법)
//def square(x : Int) -> Int:
//    ...
// swift 의 함수 모양. 역시 후위 반환 타입 사용
//func square(x : Int) -> Int
//{
//}
