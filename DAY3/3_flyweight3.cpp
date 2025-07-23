﻿#include <iostream>
#include <string>
#include <map>
#include "helper.h"

class Image
{
	std::string image_url;

	Image(const std::string& url) : image_url(url)
	{
		std::cout << url << " Downloading..." << std::endl;
	}

public:	
	void draw() { std::cout << "Draw " << image_url << std::endl; }

	friend class ImageFactory;
			// ImageFactory 에서는 Image 의 private 접근 가능
};

// SRP(Single Responsibility Principle)
// => 단일 책임의 원칙
// => 하나의 클래스는 하나의 책임만

// Image : 그림 한개를 관리
// ImageFactory : Image 객체의 생성과 공유를 관리

class ImageFactory
{
	MAKE_SINGLETON(ImageFactory)

	std::map<std::string, Image*> image_map;
public:
	Image* create(const std::string& url)
	{
		Image* img = nullptr;

		auto ret = image_map.find(url);

		if ( ret == image_map.end() )
		{
			img = new Image(url);

			image_map[url] = img;
		}
		else 
		{
			img = ret->second; 
		}
		return img;
	}
};

int main()
{
	ImageFactory factory;

	Image* img1 = factory.create("www.naver.com/a.png");
	img1->draw();

	Image* img2 = factory.create("www.naver.com/a.png");
	img2->draw();

}



