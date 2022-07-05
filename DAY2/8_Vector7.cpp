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

		for (int i = 0; i < sz; i++)
		{
			ptr[i] = value;
		}
	}
	~vector() { delete[] ptr; }

	int& at(int idx) { return ptr[idx]; }

	
	void resize(int newsize)
	{
		if (newsize > sz) // 커지는 경우.
		{
			int* tmp = new int[newsize];

			memcpy(tmp, ptr, sizeof(int) * sz);

			delete[] ptr;

			ptr = tmp;

			sz = newsize;
		}
		else
		{
			// 작아지는 경우.. 어떻게 하는것이 최선일까요 ?
			// 과제로 해보세요.. 금요일날 STL 시간에 배웁니다.
		}
	}

};

int main()
{
	vector v1(5, 3);  

	v1.at(0) = 10; 

	
	v1.resize(10); // 만들어 봅시다.


	std::cout << v1.at(0) << std::endl; // 10
}