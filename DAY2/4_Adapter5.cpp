#include <iostream>
#include <list>
#include <vector>
#include <deque>


template<typename T, typename C = std::deque<T> >
class stack 
{
	C c;
public:
	void push(const T& e) { c.push_back(e);}
	void pop() 			  { c.pop_back();}
	T& top() 			  { return c.back();}
};

int main()
{
	stack<int, std::vector<int>> s1; // vector 를 stack 처럼 보이게해달라
	stack<int, std::list<int>> s2;   // list   를 stack 처럼 보이게해달라
	
	stack<int> s;
	s.push(10);

}
