#include <iostream>
#include <string>
#include <thread>
#include <chrono>

/*
	Proxy Pattern
		=> 다양한 이유로 기존 클래스를 대신하는 것을 만들어 사용하는 패턴.

	DNSProxy 는 DNS 에 Cache 기능을 추가했음. --> 이거 기능의 추가 (Decorator)  pattern 아님??

		decorator : origin 도 계속 사용가능 (요건 기능이 옵션같은 거고 origin 은 계속 사용가능)
		proxy : origine 을 대신해서 사용 (이건 origin 을 아예 대체하는 개념)

			FileStream fs("a.txt");
			ZipDecorator zd(&fs);
			zd.write("aaa");
			fs.write("aaa");


*/

// Domain Name Server : url => ip 로 변경
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

		std::this_thread::sleep_for(std::chrono::seconds(3));

		return "100.100.100.100";
	}
};

// 대행자를 만들어 봅시다.
class DNSProxy : public IDNS
{
public:
	std::string resolve(const std::string& url)
	{
		if (url == "www.samsung.com") {
			// 자주 사용되는 url은 파일등에 정보를 기록해 놓고, 서버에 접속할 필요없이 기록된 정보를 반환.
			return "100.100.100.100";
		}

		// local PC 에 정보가 없을 때만 실제 DNS 객체의 기능을 사용.
		DNS dns;
		return dns.resolve(url);
	}
};

int main()
{
	//DNS dns;		// 항상 서버에 접근
	DNSProxy dns;	// 캐쉬를 먼저 조사. 정보가 없을 때만 서버에 접근.

	/*
		위 코드에서 보면 DNS dns 이거 사용하지 말고 DNSProxy 를 사용하라는 내용임. 내부적으로는 필요할 때 Proxy 내부에서 원래 객체 사용
		DNSProxy : DNS 에 Cache 기능을 추가하려고 만든 것이고 이외에도 다양한 Proxy 기술들이 있음.
	*/

	std::cout << dns.resolve("www.samsung.com") << std::endl;
}