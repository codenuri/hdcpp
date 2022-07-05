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
	~vector() {	delete[] ptr;}

	// 핵심 : reference를 반환하면 
	//       함수호출을 등호에 왼쪽에 놓을수 있습니다
	int& at(int idx) { return ptr[idx]; }
};

int main()
{
	vector v1(5, 3);  // 5개를 3으로 초기화해 달라.
	

	v1.at(0) = 10; // v1[0] = 10;


	std::cout << v1.at(0) << std::endl; // 10
}