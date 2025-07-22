#include <iostream>

// 방법 #2. 변하는 것을 다른 클래스로

// 메모리 할당기의 인터페이스
template<typename T>
struct IAllocator
{
	virtual T* allocate(std::size_t sz) = 0;
	virtual void deallocate(T* p, std::size_t sz) = 0;
	virtual ~IAllocator() {}
};

template<typename T>
class vector
{
	T* ptr;
	IAllocator<T>* alloc;
public:
	void set_allocator( IAllocator<T>* a) { alloc = a;}

	void resize(int n)
	{		
		ptr = alloc->allocate(n);	// 메모리 할당기 사용

		alloc->deallocate(ptr, n);	
	}
};

// 메모리 할당/해지 를 책임지는 "할당기" 클래스
template<typename T> 
class malloc_allocator : public IAllocator<T>
{
public:
	T* allocate(std::size_t sz) override 
	{	
		void* p = malloc(sizeof(T)* sz);
		return static_cast<T*>(p);
	}
	void deallocate(T* p, std::size_t sz) override 
	{ 
		free(p);
	}
};
int main()
{
	vector<int> v;
	malloc_allocator<int> ma;
	v.set_allocator(&ma);
	
}