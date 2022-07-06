// 3_정적멤버7
#include <iostream>


class Date
{
	int year;
	int month;
	int day;
	
	// 월별 날짜수는 모든 객체에 따로 있을필요 없습니다.
	static int days[12];

public:
	Date(int y, int m, int d) : year(y), month(m), day(d) {}

	// getter/setter
	void setYear(int y) { year = y; }  // 1 <= y 등이 유효성 조사를 하는게 좋습니다
	int  getYear()      { return year; }

	// month, day 도 추가..
	
	// 이외에 다양한 유용한 멤버를 제공하세요..
	Date afterDays(int ds)
	{
		Date temp(year, month, day + ds); // 잘못된 구현!!
						// 실제 구현은 과제로 해보세요
						// 단, 하실수 있다면 "윤년"도 고려해서 해보세요
		return temp;
	}

	// 아래 함수의 구현은 "기준 날짜"가 필요한 것은 아닙니다.
	// 객체가 없어도 호출가능하게 만드는 것이 좋습니다
	static int howManyDays(int m) { return days[m - 1]; }


	// 아래 멤버 함수는 반드시 "기준날짜(객체)"가 필요합니다.
	// static 멤버 함수로 만들수는 없습니다.
	Date tomorrow()
	{
		Date temp(year, month, day + 1); // 잘못된 구현
		return temp;
	}

};
int Date::days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


int main()
{
	Date d2(2022, 7, 4); 

	Date d3 = d2.afterDays(1000); // 1000일 후의 날짜

	// 3월이 몇일까지 있는지 알고 싶다.
	int ds1 = d2.howManyDays(3);
	int ds2 = Date::howManyDays(3);

	
	Date d4 = d2.tomorrow();

}



