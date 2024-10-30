#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// Domain Name Server : url => ip �� ����
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

// DNS �� �����ڸ� ����� ���ô�.
class DNSProxy : public IDNS
{
public:
	std::string resolve(const std::string& url)
	{
		if (url == "www.samsung.com")
		{
			// ���� ���Ǵ� url �� ���ϵ ������ ����� ����
			// ������ �������ʿ� ���� ��ϵ� ������ ��ȯ�մϴ�.
			return "100.100.100.100";
		}

		// LOCAL PC �� �������������� ���� DNS ��ü�� ����� ����մϴ�.
		DNS dns;
		return dns.resolve(url);
	}
};


int main()
{
//	DNS dns;		// �׻� ������ ����
	DNSProxy dns;	// ĳ���� ���� ����
					// ������ �������� ������ ����

//	std::cout << dns.resolve("www.samsung.com") << std::endl;
	std::cout << dns.resolve("www.naver.com") << std::endl;
}

// Proxy  ����
// => �پ��� ������ ���� Ŭ������ ����ϴ� ���� ����� ����ϴ� ����

// DNSProxy �� DNS �� Cache ����� �߰��ϹǷ�
// => ����� �߰�(decorator) ���� �ƴѰ��� ??

// decorator : origin �� ��� ��밡��...
// proxy     : origin �� ����ؼ� ���

FileStream fs("a.txt");
ZipDecorator zd(&fs);
zd.write("aaa"); // ����� �߰��� ���� ����ص� �ǰ�
fs.write("aaa"); // origin �� ��밡��. 

// proxy
//DNS dns; // �̰��� ������� ����!!
DNSProxy dns; // �̰��� ����ض�!!
			  // Proxy �� �ʿ��Ҷ� ���� ��ü ���

// DNSProxy : DNS �� ĳ�� ����� �߰��Ϸ��� �����
// �̿ܿ��� �پ��� Proxy ����� �ֽ��ϴ�. - ��������.