// this.cpp

class Point 
{
	int x, y;
public:
	void set1(int a, int b) // void set1(Point* this, int a, int b) 
	{ 
		x = a; 				// this->x = a;
		y = b;				// this->y = b;
	}

	// C++23 부터 this 를 명시적으로 받을수 있게 됩니다.
	// => 파이썬 처럼
	// => 이게 장점이 많다는 점을 깨 닫기 되었습니다.
	// => 그래서, C++23 이후 아래 코드를 많이 보게 됩니다.
	void set2( this Point& self, int a, int b)
	{
		self.x = a;
		self.y = b;
	}
};
int main()
{
	Point p1, p2;

	p1.set1(10,20); // 원리는 set1(&p1, 10, 20) 입니다.
	p1.set2(10,20); 
}