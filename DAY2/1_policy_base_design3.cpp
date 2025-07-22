#include <iostream>

// 방법 #2. 변하는 것을 다른 클래스로

// 메모리 할당기의 인터페이스
template<typename T>
struct ISync
{
	virtual T* allocate(std::size_t sz) = 0;
	virtual void deallocate(T* p, std::size_t sz) = 0;
	virtual ~ISync() {}
};




template<typename T>
class vector
{
	T* ptr;
public:
	void resize(int n)
	{
		//......
		ptr = allocate(n);	// 메모리 할당이 필요하면 가상함수 호출

		//.....
		deallocate(ptr, n);	// 메모리 메모리 해지도 가상함수 호출
	}
	virtual T* allocate(std::size_t sz) { return new T[sz];}
	virtual void deallocate(T* p, std::size_t sz) { delete[] p;}
};


template<typename T> 
class malloc_vector : public vector<T>
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
	malloc_vector<int> v;
	
}