// vector.cpp
#include "vector.h"

vector::vector(int n, int value /* = 0 */) //<== 주의. 디폴트값은 선언에만
{
	sz = n;
	ptr = new int[sz];

	for (int i = 0; i < sz; i++)
	{
		ptr[i] = value;
	}
}
vector::~vector() { delete[] ptr; }

int& vector::at(int idx) { return ptr[idx]; }


void vector::resize(int newsize)
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

int vector::size() { return sz; }
bool vector::empty() { return sz == 0; }

