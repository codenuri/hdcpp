#include <thread>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

constexpr std::size_t sz = 1000000;

std::vector<int> v;

void init()
{
	v.reserve(sz); // 메모리만 먼저 할당

    for (int i = 0; i < sz; ++i)
    {
        v.push_back(i);
    }
}
//---------------------------------------------
// 구간의 합 구하기
template<typename IT, typename RT>
void sum(IT first, IT last, RT& result)
{
	while( first != last )
	{
		result += *first;
		++first;
	}
}

int main()
{
    init();

    long long s = 0;
    sum(v.begin(), v.end(), s);

	std::cout << s << std::endl; 
}
