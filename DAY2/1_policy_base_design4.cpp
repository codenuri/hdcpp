#include <iostream>

// 방법 #3. 변하는 것을 다른 클래스로


template<typename T, typename Alloc>
class vector
{
	T* ptr;
	
	Alloc alloc;
public:	

	void resize(int n)
	{		
		ptr = alloc.allocate(n);	

		alloc.deallocate(ptr, n);	
	}
};

// 메모리 할당/해지 를 책임지는 "할당기" 클래스
template<typename T> 
class malloc_allocator
{
public:
	inline T* allocate(std::size_t sz) 
	{	
		void* p = malloc(sizeof(T)* sz);
		return static_cast<T*>(p);
	}
	inline  void deallocate(T* p, std::size_t sz) 
	{ 
		free(p);
	}
};
int main()
{
	vector<int, malloc_allocator<int>> v;
	
}