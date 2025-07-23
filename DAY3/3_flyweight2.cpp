#include <iostream>
#include <string>
#include <map>


class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}

public:	
	void draw() { std::cout << "Draw " << image_url << std::endl; }

	// 의미 : 객체 생성이 한곳에서만 이루어집니다.
	// => 만들어진 객체를 자료구조로 관리할수 있습니다

	inline static std::map<std::string, Image*> image_map;

	static Image* create(const std::string& url)
	{
		Image* img = nullptr;

		auto ret = image_map.find(url);

		if ( ret != image_map.end() )
		{
			img = new Image(url);

			image_map[url] = img;
		}
		else 
		{
			img = ret->second; // map 의 반복자는 first 가 키값
								// second 가 value. 즉, Image 객체
		}
		return img;
	}
};







int main()
{
	Image* img1 = Image::create("www.naver.com/a.png");
	img1->draw();

	Image* img2 = Image::create("www.naver.com/a.png");
	img2->draw();

}



