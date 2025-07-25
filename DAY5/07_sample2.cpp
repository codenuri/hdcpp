#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <numeric>
// 예제
int main()
{
    std::vector<int> v1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> v2(10);

    // 작업 1. v1의 부분합을 구해서 v2에 넣기
    std::partial_sum(v1.begin(), v1.end(), v2.begin()); 

	
	std::promise<int> pro;  // 받을것은 없고, 끝났는지만 알면 됩니다
	std::future<int> ft = pro.get_future();

	// 작업 3을 새로운 스레드로 수행합니다.
	// 스레드를 위해 일반함수로 하면 아래 처럼 인자를 보내야 합니다.
	// std::thread t( foo, std::ref(v2), std::ref(pro) );

	// => 이경우 람다가 편리합니다.
	std::thread t([&v2, &pro] () {  

		int s = std::accumulate(v2.begin(), v2.end(), 0);

		pro.set_value(s);

	} );




    // 작업 2. v2 의 모든 요소를 화면 출력
    for (auto n : v2)
        std::cout << n << ", ";


    // 작업 3. v2의 모든 요소의 합을 구하기
    

	
    // 작업 4. 결과 출력
    std::cout << "\n" << s << std::endl;
}



