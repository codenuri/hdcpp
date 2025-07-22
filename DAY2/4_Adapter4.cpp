#include <iostream>
#include <list>
#include <vector>
#include <deque>

// 상속 : 구현 뿐 아니라 인터페이스도 상속 받겠다.
//        기반 클래스(std::list) 의 모든 함수를 stack 도외부 노출

// 포함 : 구현만 상속(재사용)하겠다. 인터페이스는 상속 받지 않겠다.

template<typename T>
class stack 
{
	std::list<T> c;
public:
	void push(const T& e) { c.push_back(e);}
	void pop() 			  { c.pop_back();}
	T& top() 			  { return c.back();}
};

int main()
{
	stack<int> s;
	s.push(10);

	// 단점 : 아래처럼 사용할수 없게해야 합니다
	s.push_front(20); //!!!

}
