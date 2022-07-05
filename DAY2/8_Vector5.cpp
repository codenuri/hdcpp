#include <iostream>

class vector
{
	int* ptr;
	int  sz;
public:
	vector(int n, int value = 0)
	{
		sz = n;
		ptr = new int[sz];

		memset(ptr, value, sizeof(int) * sz);
	}
	// 생성자에서 new 등으로 메모리를 할당했다면 소멸자에서 delete 하면됩니다.
	~vector() 
	{
		delete[] ptr; 
	}

};

int main()
{
	vector v1(5, 3);  // 5개를 3으로 초기화해 달라.
	vector v2(5);     // 5개를 0으로 초기화해 달라.
}