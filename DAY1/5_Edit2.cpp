#include <iostream>
#include <string>
#include "getch.h" 

// 핵심 : validation 정책은 변경 가능해야 합니다
// => Edit 는 라이브러리 이므로 Edit 자체 수정은 없어야 합니다.

// 방법 #1. 변하는 것을 가상함수로

class Edit
{
	std::string data;
public:

	// 변해야 하는 부분(validation 정책) 을 가상함수로 분리
	virtual bool validate( char c)
	{
		return true;
	}

	std::string get_data()
	{
		data.clear(); 
		while( 1 )
		{
			char c = _getch();
			
			if ( c == 13 ) break;
			
			if ( validate(c) ) // validation 정책은 가상함수에 의존
			{
				data.push_back(c);
				std::cout << c;
			}			
		}
		std::cout << '\n';

		return data;
	}
};

int main()
{
	Edit e;
	while (1)
	{
		std::cout << e.get_data() << std::endl;
	}
}


