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

// Adapter  종류
// class Adapter        : 클래스의 인터페이스 변경
// object(객체) Adapter : 객체의 인터페이스 변경

class Text : public TextView,  
			 public Shape      
{
public:
	Text(const std::string& data) : TextView(data) {}

	void draw() override 
	{
		TextView::show();
	}
};

int main()
{
	std::vector<Shape*> v;

	TextView tv("abcd"); // TextView : 클래스
						 // tv : 객체

	// 이미 생성된 "객체 tv" 를 v에 넣을수 있을까요 ?
	v.push_back(&tv); // ???
}







