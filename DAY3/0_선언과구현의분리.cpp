#include <iostream>

// 어제 소스에서 vector8.cpp 소스에서
// vector 클래스만 복사해 오세요

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
		if (newsize > sz)
		{
			int* tmp = new int[newsize];

			memcpy(tmp, ptr, sizeof(int) * sz);

			delete[] ptr;

			ptr = tmp;

			sz = newsize;
		}
		else
		{
		}
	}

	int size() { return sz; }
	bool empty() { return sz == 0; }
};

int main()
{
	vector<int>    v1(5, 3);
	vector<double> v2(5, 3.1);

	v1.at(0) = 10;
	v1.resize(10);
	
	std::cout << v1.at(0) << std::endl;
	std::cout << v1.size() << std::endl;

}
