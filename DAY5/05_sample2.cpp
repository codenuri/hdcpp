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
	v.reserve(sz); 

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
template<typename IT, typename RT>
void parallel_sum(IT first, IT last, RT& result)
{
	// #1. first ~ last 사이의 요소 갯수
	// 					last - first : vector만 가능. list 안됨
    auto cnt_element = std::distance(first, last); // 모두 가능

    if (cnt_element == 0) return;

	// #2. 현재 PC 의 논리프로세서의 갯수(CPU * 2)
	// => 아래 함수는 일부환경에서는 0 나올수 있습니다.
    std::size_t cnt_hw_thread = std::thread::hardware_concurrency();

    if (cnt_hw_thread == 0)
        cnt_hw_thread = 2;

	// #3. 한개의 스레드가 수행할 최소 요소 갯수
    const std::size_t cnt_per_thread = 4000;

	// 전체요소와 최소요소갯수를 사용해서 스레드 갯수 파악
    const std::size_t max_cnt_thread =
        (cnt_element + cnt_per_thread - 1) / cnt_per_thread;

	// #4. 하드웨어를 고려한 실제 필요한 스레드 갯수 계산
    const std::size_t cnt_thread =
        std::min(cnt_hw_thread, max_cnt_thread);

	std::cout << "thread count : "	<< cnt_thread << std::endl;

	//----------------------------------------------------------
	// 스레드 한개당 처리할 요소 갯수
    const std::size_t block_size = cnt_element / cnt_thread;

	// 4개 스레드가 필요했다면, 실제는 3개만 생성, 한개는 주스레드
    std::vector<std::thread> thread_vec(cnt_thread - 1);
    std::vector<RT> result_vec(cnt_thread);

    IT start = first;

    for (int i = 0; i < cnt_thread - 1; ++i)
    {
        IT end = std::next(start, block_size);

        thread_vec[i] = std::thread(sum<std::vector<int>::iterator, long long>,
           					 start, end, std::ref(result_vec[i]));

        start = end;
    }
	// 마지막 작업은 주스레드가!
    sum(start, last, result_vec[cnt_thread - 1]);

    for (auto& t : thread_vec)
        t.join();

	// 모든 스레드 종료 대기후, result_vector 의 내용을 합하면 됩니다.
    RT ret = std::accumulate(result_vec.begin(), result_vec.end(), 0);

    result = ret;
}

int main()
{
    init();

    long long s = 0;
    sum(v.begin(), v.end(), s);

	std::cout << s << std::endl; 
}
