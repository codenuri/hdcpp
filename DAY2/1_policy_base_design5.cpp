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
}
