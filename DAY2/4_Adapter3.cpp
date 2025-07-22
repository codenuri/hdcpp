#include <iostream>
#include <list>
#include <vector>
#include <deque>

// list 의 인터페이스(함수이름)을 변경해서 stack 을 만들어 봅시다.
template<typename T>
class stack : public std::list<T>
{
public:
	void push(const T& e) {}
	void pop() {}
	T& top() {}
};


int main()
{
	stack<int> s;
	s.push(10);
}
