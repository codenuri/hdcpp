#include <iostream>
#include <vector>

template<typename T> 
class debug_alloc
{
public:
	inline T* allocate(std::size_t sz) 
	{	
		void* p = malloc(sizeof(T)* sz);

		printf("[allocate] %p, %dcnt\n", p, sz);

		return static_cast<T*>(p);
	}
	inline  void deallocate(T* p, std::size_t sz) 
	{ 
		printf("[deallocate] %p, %dcnt\n", p, sz);
		free(p);
	}

	// 사용자 정의 컨테이너 만들때는 아래 3개가 더 필요
	// => 관례적인 코드 무조건 복사해서 이름만 변경후 사용하면 됩니다.
	using value_type = T;

	debug_alloc() {}

	template<typename U>
	debug_alloc(const debug_alloc<U>&) {}  // generic 생성자라는 개념
};

int main()
{
//	std::vector<int> v; // == std::vector<int, std::allocator<int>> 의 의미

	std::vector<int, debug_alloc<int> > v;	

	std::cout << "-----------------" << std::endl;

	v.resize(5);

	std::cout << "-----------------" << std::endl;

	v.resize(10);	// 1. 10개 메모리 할당 - 로그
					// 2. 5개 메모리 내용 => 10개 버퍼에 복사
					// 3. 5개 메모리 해지 - 로그

	std::cout << "-----------------" << std::endl;	

	v.resize(7);	// 크기가 줄어들때는 메모리 재할당 없음
					// size : 7
					// capacity(메모리사용량) : 10
	
	std::cout << v.size() << ", " << v.capacity() << std::endl;

	std::cout << "-----------------" << std::endl;		
}
