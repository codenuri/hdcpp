#include <iostream>
#include <list>
#include <vector>
#include <deque>

// list 의 인터페이스(함수이름)을 변경해서 stack 을 만들어 봅시다.
template<typename T>
class stack : public std::list<T>
{
public:
	void push(const T& e) { std::list<T>::push_back(e);}
	void pop() 			  { std::list<T>::pop_back();}
	T& top() 			  { return std::list<T>::back();}
};

int main()
{
	stack<int> s;
	s.push(10);

	// 단점 : 아래처럼 사용할수 없게해야 합니다
	s.push_front(20); //!!!

}
