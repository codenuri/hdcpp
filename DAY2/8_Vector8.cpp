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

	// 이제 "어떤 멤버함수를 제공하면 사용자가 좋아할까 ??" 
	// 를 많이 생각해 보세요.
	// 최대한 유용한 멤버 함수를 제공해 주세요
	int size() { return sz; }
	bool empty() { return sz == 0; }
};

int main()
{
	vector v1(5, 3);
	v1.at(0) = 10;
	v1.resize(10); 
	std::cout << v1.at(0) << std::endl; 
	std::cout << v1.size() << std::endl;

}