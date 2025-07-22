#include <iostream>
#include <string>
#include <vector>

// 아래 클래스가 이미 있었다가 가정해 봅시다.

class TextView
{
	std::string data;
	// font_name, font_size, bold, color 등의 정보
public:
	TextView(const std::string& s) : data(s) {}

	void show() { std::cout << data << std::endl; }
};

//=================================================
class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};


class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw circle" << std::endl; }
};

// 도형편집기 시스템에 "문자열" 을 다루는 클래스를 추가하고 싶다.
// => 그런데!! 예전에 사용하던 "TextView" 의 기능이면 딱 좋을거 같다!!!
// => 여기서 TextView 를 사용할수 있을까 ?

// TextView 의 인터페이스를 변경(show=> draw 로 변경)해서
// 도형편집기에서 사용할수 있게 하자

class Text : public TextView,  // 기능 물려받고
			 public Shape      // 도형편집기 요구사항 만족
{
public:
	Text(const std::string& data) : TextView(data) {}

	void draw() override 
	{
		?;
	}
};

int main()
{
	std::vector<Shape*> v;
}







