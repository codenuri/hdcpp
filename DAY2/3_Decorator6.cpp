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

int main()
{
	// File 에 쓸때 암호화 해서 쓰는 기능이 필요 합니다.
	// 최선의 디자인을 생각해 봅시다.

	// #1. 데이타를 먼저 암호화 하고 쓰자
	// => 매번 암호화 코드 작성하면 불편하다.

	// #2. FileStream 의 파생 클래스인 EncryptFileStream 만들자
	// => FileStream 뿐 아니라, NetworkStream, PipeStream 도 필요
	// => 암호화 외에 압축등이 필요하고, 중첩이 필요하면 복잡해진다


	// #3. Decorator 패턴을 사용하면 어떨까 ?

	FileStream fs("a.txt");
	fs.write("hello"); // 

	ZipDecorator zd(&fs);
	zd.write("hello"); // 1. 데이타를 압축하고
						// 2. fs.write(압축된 데이타)

	EncryptDecorator ed(&zd); // 1. 암호화 하고
	ed.write("hello");		  // 2. ed.write(암호화된 데이타)
}

// 실제 구현은 다음소스