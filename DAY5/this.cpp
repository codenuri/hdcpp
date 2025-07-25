// this.cpp

class Point 
{
	int x, y;
public:

	void set1(int a, int b) 
	{ 
		x = a; 
		y = b;
	}
};

int main()
{
	Point p1, p2;

	p1.set1(10,20); // 원리는 set1(&p1, 10, 20) 입니다.
}