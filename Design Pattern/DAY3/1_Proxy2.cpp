#include <iostream>
#include <string>
#include <thread>
#include <chrono>

/*
	Proxy Pattern
		=> �پ��� ������ ���� Ŭ������ ����ϴ� ���� ����� ����ϴ� ����.

	DNSProxy �� DNS �� Cache ����� �߰�����. --> �̰� ����� �߰� (Decorator)  pattern �ƴ�??

		decorator : origin �� ��� ��밡�� (��� ����� �ɼǰ��� �Ű� origin �� ��� ��밡��)
		proxy : origine �� ����ؼ� ��� (�̰� origin �� �ƿ� ��ü�ϴ� ����)

			FileStream fs("a.txt");
			ZipDecorator zd(&fs);
			zd.write("aaa");
			fs.write("aaa");


*/

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

		std::this_thread::sleep_for(std::chrono::seconds(3));

		return "100.100.100.100";
	}
};

// �����ڸ� ����� ���ô�.
class DNSProxy : public IDNS
{
public:
	std::string resolve(const std::string& url)
	{
		if (url == "www.samsung.com") {
			// ���� ���Ǵ� url�� ���ϵ ������ ����� ����, ������ ������ �ʿ���� ��ϵ� ������ ��ȯ.
			return "100.100.100.100";
		}

		// local PC �� ������ ���� ���� ���� DNS ��ü�� ����� ���.
		DNS dns;
		return dns.resolve(url);
	}
};

int main()
{
	//DNS dns;		// �׻� ������ ����
	DNSProxy dns;	// ĳ���� ���� ����. ������ ���� ���� ������ ����.

	/*
		�� �ڵ忡�� ���� DNS dns �̰� ������� ���� DNSProxy �� ����϶�� ������. ���������δ� �ʿ��� �� Proxy ���ο��� ���� ��ü ���
		DNSProxy : DNS �� Cache ����� �߰��Ϸ��� ���� ���̰� �̿ܿ��� �پ��� Proxy ������� ����.
	*/

	std::cout << dns.resolve("www.samsung.com") << std::endl;
}