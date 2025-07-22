// 디자인 패턴을 열심히 공부하면!!! 언제가는
// => 서로 다른 패턴이 "동일해 보입니다."
// => 항상 의도를 생각하세요

// ZipDecorator 복사
class ZipDecorator : public Stream  
{
	Stream* origin;
public:
	ZipDecorator(Stream* s) : origin(s) {}

	void write(const std::string& data) override 
	{
		auto s = "[ " + data + "] 압축됨"; 
		origin->write(s);				   
	}
};

// ObjectAdapter 복사
class ObjectAdapter : public Shape      
{
	TextView* origin; 					  
public:
	ObjectAdapter(TextView* tv) : origin(tv) {}

	void draw() override 
	{
		origin->show();
	}
};

// 의도 
// Decorator : 기능의 추가. 인터페이스는 동일
FileStream fs("a.txt");
ZipDecorator zd(&fs);
fs.write("hello"); //
zd.write("hello"); // 원본과 동일한 사용법. 하지만 기능 추가

// Adapter : 인터페이스 변경. 기능 동일
TextView tv("abcd");
ObjectAdapter oa(&tv);

tv.show(); 
oa.draw(); // 함수 이름이 변경됨. 기능은 동일