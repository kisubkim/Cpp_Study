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
		std::cout << "������ �����ؼ� "
			<< url << "�� ���� IP ���� �����\n";

		std::this_thread::sleep_for(std::chrono::seconds(3)); // 3�ʴ��

		return "100.100.100.100";
	}
};

// DNS Ŭ������ ��� �ؼ� ����Ҽ� �ִ� "������(proxy)" �� ����� ���ô�.

class DNSProxy : public IDNS
{
public:
	std::string resolve(const std::string& url)
	{
		if (url == "www.samsung.com") // local DB �� �ִ� �� �����ϴ� �ڵ�
			return "100.100.100.100"; // ��� ����

		// cache(local db) �� ���� ���� DNS Ŭ���� ���
		DNS dns;
		return dns.resolve(url);
	}
};

int main()
{
	//	DNS dns;		// ���� ����ڿ��� �̰��� ������� ����
	DNSProxy dns;	// �̰��� ����ϰ� �մϴ�.

	std::cout << dns.resolve("www.samsung.com") << std::endl;
	std::cout << dns.resolve("www.naver.com") << std::endl;
}

// DNSProxy ó�� ������ ���� ����ϴ� ���� ����� ������ 
// "Proxy" ���� �Դϴ�.

// virtual proxy : ��� ��ü(�ð��� �ɸ��� �۾�, �޸� ��뷮 ���� �۾�)
//				   �� ������ �ִ��� ���� ��Ű�� ���� proxy

// DNSProxy : DNS ��� + cache ��� �߰� �̹Ƿ� "decorator" �ƴ� ���� ?

// decorator vs proxy
// => ��� "� ��� �߰�" �� ������ �ֱ� ������

// decorator : original �� ���� ����
// proxy     : ��� ���. original �� ������� ���� ��� ����϶�� ��.
//		       original �� �ʿ��Ҷ��� ����

FileStream fs("a.txt");
ZipDecorator zd(&fs);

// fs�� ��밡���ϰ�, zd �� ��밡��