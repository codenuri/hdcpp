#include <iostream>

// 방법 #3. 변하는 것을 다른 클래스로

#include <memory> 

// std::allocator<T> : C++ 표준에 있는 메모리 할당기
//                     내부적으로 new/delete 사용
template<typename T, typename Alloc = std::allocator<T> >
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
//	vector<int, malloc_allocator<int>> v;
	vector<int> v; // std::allocator<int> 사용
	
}