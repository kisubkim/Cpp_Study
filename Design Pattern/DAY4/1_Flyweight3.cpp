// 1_Flyweight - 167
#include <iostream>
#include <string>
#include <map>
#include "helper.h"

/*
	아래 Image는 2가지 기능을 하고 있음.
		1. 자기 자신을 생성과 공유
		2. 자기 자신을 출력
	
	--> Image는 그림 다운로드와 출력의 기능만 가지고 Image의 생성/공유는 다른 클래스로 이동. ==> Factory 도입.
*/


class Image
{
	std::string image_url;
	Image(const std::string& url) : image_url(url) {
		std::cout << url << " Downloading..." << std::endl;
	}

public:
	void Draw() { std::cout << "Draw " << image_url << std::endl; }

	friend class ImageFactory;		// ImageFactory class에서는 Image Private 접근 가능하게.
};


class ImageFactory {
	MAKE_SINGLETON(ImageFactory)

		std::map<std::string, Image*> image_map;
public:
	Image* Create(const std::string& url) {
		auto it = image_map.find(url);
		if (it == image_map.end()) {
			return (image_map[url] = new Image(url));
		}
		return it->second;
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



