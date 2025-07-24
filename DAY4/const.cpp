//const.cpp 
class Point
{
public:
	int x = 0;
	int y = 0;

	void set(int a, int b) { x = a; y = b;}
	void print() 
	{
		std::cout << x << std::endl;
	}
};
int main()
{
	Point p;
	p.x = 10;
	p.set(1, 2);
	p.print();
}