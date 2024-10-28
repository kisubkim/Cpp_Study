#include <iostream>
#include <string>
#include <thread>
#include <chrono>


struct IDNS
{
	virtual std::string resolve(const std::string& url) = 0;
	virtual ~IDNS() {}
};

class DNS : public IDNS
{
public:
	std::string resolve(const std::string& url)
	{
		std::cout << "서버에 접속해서 "
			<< url << "에 대한 IP 정보 얻는중\n";

		std::this_thread::sleep_for(std::chrono::seconds(3)); // 3초대기

		return "100.100.100.100";
	}
};

// DNS 클래스를 대신 해서 사용할수 있는 "대행자(proxy)" 를 만들어 봅시다.

class DNSProxy : public IDNS
{
public:
	std::string resolve(const std::string& url)
	{
		if (url == "www.samsung.com") // local DB 에 있는 지 조사하는 코드
			return "100.100.100.100"; // 라고 가정

		// cache(local db) 에 없을 때만 DNS 클래스 사용
		DNS dns;
		return dns.resolve(url);
	}
};

int main()
{
	//	DNS dns;		// 이제 사용자에게 이것을 사용하지 말고
	DNSProxy dns;	// 이것을 사용하게 합니다.

	std::cout << dns.resolve("www.samsung.com") << std::endl;
	std::cout << dns.resolve("www.naver.com") << std::endl;
}

// DNSProxy 처럼 기존의 것을 대신하는 것을 만드는 패턴을 
// "Proxy" 패턴 입니다.

// virtual proxy : 비싼 객체(시간이 걸리는 작업, 메모리 사용량 많은 작업)
//				   의 생성을 최대한 지연 시키기 위한 proxy

// DNSProxy : DNS 기능 + cache 기능 추가 이므로 "decorator" 아닌 가요 ?

// decorator vs proxy
// => 모두 "어떤 기능 추가" 의 개념이 있긴 하지만

// decorator : original 에 접근 가능
// proxy     : 대신 사용. original 을 사용하지 말고 대신 사용하라는 것.
//		       original 을 필요할때만 생성

FileStream fs("a.txt");
ZipDecorator zd(&fs);

// fs도 사용가능하고, zd 도 사용가능