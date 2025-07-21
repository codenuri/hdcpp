#include <iostream>
#include <string>
#include "getch.h" 

// 변하는 것을 분리하는 2가지 기술
// #1. 변하는 것을 가상함수로 => template method
// #2. 변하는 것을 다른 클래스로 => strategy 패턴

// Validation 만 수행하는 클래스
// 교체 가능한 설계를 위해서 인터페이스 필요
struct IValidator
{
	virtual bool validate(const std::string& s, char c) = 0;
	virtual bool is_complete(const std::string& s) { return true;}

	virtual ~IValidator() {}
};

// 주민 등록 번호 : 831    1    확인



class LimitDigitValidator
{
	int value;
public:
	LimitDigitValidator(int n) : value(n) {}

	bool validate(const std::string& s, char c)
	{
		return s.size() < value && isdigit(c);
	}
};


class Edit
{
	std::string data;

	LimitDigitValidator* val = nullptr;

public:
	std::string get_data()
	{
		data.clear(); 
		while( 1 )
		{
			char c = _getch();
			
			if ( c == 13 ) break;
			
			if ( isdigit(c) )
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


