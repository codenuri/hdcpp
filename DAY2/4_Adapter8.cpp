#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class take_view 
{
	T& container;
	int cnt;
public:
	take_view(T& t, int c) : container(t), cnt(c) {}

	auto begin() { return container.begin();}
	auto end() { return std::next(container.begin(), cnt);}
};

class reverse_view 
{
	T& container;
public:
	reverse_view(T& t) : container(t) {}

	auto begin() { return container.rbegin();}
	auto end() { return container.rend();}
};

// 편의를 위해 reverse_view 를 만드는 함수를 제공합니다.
template<typename T>
reverse_view<T> reverse(T& c)
{
	return reverse_view<T>(c);
}

int main()
{
	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for( auto e : reverse(v)) // 파이썬과 동일!
	{
		std::cout << e << std::endl;
	}

}
