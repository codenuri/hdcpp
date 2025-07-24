class Rect
{
	int x = 0, y = 0, w = 0, h = 0;	
public:
	int get_area() { return w * h;}
};

void foo( Rect rc)
{
	int n = rc.get_area();
}

int main()
{
	Rect r;
	int n = r.get_area();
	foo(r);
}