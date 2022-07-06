// vector.h
#pragma once

class vector
{
	int* ptr;
	int  sz;
public:
	vector(int n, int value = 0);
	~vector();
	int& at(int idx);
	void resize(int newsize);
	int size();
	bool empty();
};
