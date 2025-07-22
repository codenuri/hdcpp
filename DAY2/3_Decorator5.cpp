#include <iostream>


// FileStream, NetworkStream, PipeStream 등
// 모든 Stream 의 공통의 인터페이스(사용법을 동일하기 위해 이름약속)
struct Stream
{
	virtual void write(const std::string&) = 0;
	virtual ~Stream() {}

	// 이외에도 read, flush, is_open 등의 다양한 함수를 여기서 약속
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
	FileStream fs("a.txt");
	fs.write("hello");

//	NetworkStream ns("100.100.100.100", 3000);
//	ns.write("hello");


//	PipeStream ps("mynamedpipe");
//	ps.write("hello");
}
