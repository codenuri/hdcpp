#include <iostream>

// 방법 #1. 변하는 것을 가상함수로 분리
// => template method

// 단점
// => vector 뿐 아니라 다양한 컨테이너가 있다.
// => 이 방식으로 설계되면
// => vector, list, map 등의 컨테이너 각각 파생 클래스를 만들어야 한다.
// => 메모리 할당 알고리즘을 공유 할수 없다.  

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

// 의도 : 메모리 할당 방식을 변경하려면 파생클래스를 만들어서 
//       약속된 가상함수를 override 
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