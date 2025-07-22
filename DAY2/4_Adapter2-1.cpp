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