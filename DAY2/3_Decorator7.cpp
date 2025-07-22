#include <iostream>

struct Stream
{
	virtual void write(const std::string&) = 0;
	virtual ~Stream() {}
};


class FileStream : public Stream
{
	FILE* file;
public:
	FileStream(const char* s, const char* mode = "wt")
	{
		file = fopen(s, mode);
	}
	~FileStream() { fclose(file); }

	void write(const std::string& s) 
	{
		printf("%s 쓰기\n", s.c_str() );
	}
};

// Stream 에 기능을 추가하는 Decorator
class ZipDecorator : public Stream  // <== 중첩된 추가를 위해서 상속
{
	Stream* origin;
public:
	ZipDecorator(Stream* s) : origin(s) {}

	void write(const std::string& data) override 
	{
		auto s = "[ " + data + "] 압축됨"; // 추가된 기능
		origin->write(s);				   // origin 객체에 전달	
	}
};

class EncryptDecorator : public Stream  
{
	Stream* origin;
public:
	EncryptDecorator(Stream* s) : origin(s) {}

	void write(const std::string& data) override 
	{
		auto s = "[ " + data + "] 암호화됨";
		origin->write(s);				   
	}
};


int main()
{


	FileStream fs("a.txt");
	fs.write("hello"); // 

	ZipDecorator zd(&fs);
	zd.write("hello"); // 1. 데이타를 압축하고
						// 2. fs.write(압축된 데이타)

	EncryptDecorator ed(&zd); // 1. 암호화 하고
	ed.write("hello");		  // 2. ed.write(암호화된 데이타)
}

