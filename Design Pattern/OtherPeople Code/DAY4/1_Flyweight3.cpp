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
	void Draw() { std::cout << "Draw " << image_url << std::endl; }


	friend class ImageFactory;
};

// 단일 책임의 원칙(SRP) : 하나의 클래스는 하나의 책임만

// Image 객체의 생성/공유 는 별도의 클래스로 만들자
class ImageFactory
{
	MAKE_SINGLETON(ImageFactory)

		std::map<std::string, Image*> image_map;
public:
	Image* Create(const std::string& url)
	{
		Image* img = nullptr;

		auto it = image_map.find(url);

		if (it == image_map.end())
		{
			img = new Image(url);
			image_map[url] = img;
		}
		else
		{
			img = it->second;
		}
		return img;
	}

};



int main()
{
	ImageFactory& factory = ImageFactory::get_instance();

	Image* img1 = factory.Create("www.naver.com/a.png");
	img1->Draw();

	Image* img2 = factory.Create("www.naver.com/a.png");
	img2->Draw();

}
