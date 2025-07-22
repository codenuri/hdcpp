#include <iostream>
#include <vector>
#include <algorithm>

// 아래 클래스 생각해 보세요
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
int main()
{
	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	take_view tv(v, 5);

//	for( auto e : v)
	for( auto e : tv)
	{
		std::cout << e << std::endl;
	}

}
