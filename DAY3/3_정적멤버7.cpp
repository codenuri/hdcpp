// 3_정적멤버7
#include <iostream>

// 프로그램에서 "날짜" 를 다루어야 한다.
// => "Date" 타입을 설계하자
// 1. 년, 월, 일 만 관리하자.		=> 하나의 클래스는 하나의 책임만..
// 2. 년, 월, 일, 시, 분, 초를 관리하자.

class Date
{
	int year;
	int month;
	int day;
public:
	Date(int y, int m, int d) : year(y), month(m), day(d) {}
};

int main()
{
//	Date d1;			 // 이 코드가 되게 할까요 ? 안되게 할까요 ?
						// 안전한 코드를 중시한다면, 안되는게 좋습니다.
						// 하지만, 되는게 편리할수도 있습니다.
						
	Date d2(2022, 7, 4); // ok
	

}


