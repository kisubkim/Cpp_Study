#include <iostream>

/*
	"static member data" VS "static local variable"

	static 지역 변수(static local variable) : 함수를 처음 호출 했을 때 만들어짐. 호출하지 않으면 Cursor() 생성자 호출되지 않음.
											=> 지연된 초기화 (필요할 때만 초기화)

	static 멤버 데이터 (static member data) : main 함수가 실행되기 전에 Cursor 생성자 호출. 즉, 사용하지 않아도 만들어짐.
											=> main 들어가기 전에 전역변수들이 들어가는 table에 넣기 위해서 선언됨.
											(머 꼼꼼하게 보면 정확히 언제 만들어지는지도 명확하지 않음)
											=> 이른 초기화 (그냥 빨리 초기화)
*/

class Cursor {
private:
	Cursor() { std::cout << "Cursor()" << std::endl; }
	Cursor(const Cursor&) = delete;
	Cursor& operator=(const Cursor&) = delete;

	//Cursor instance;		// Error. 그냥하면 계속 루프로 들어가서 불가능. size를 알아내기 위해서 계속 자신타입으로 들어가게 됨.
	static Cursor instance;		// static member data는 자신 타입 선언 가능
public:
	static Cursor& get_instance() {
	//	static Cursor instance;
		return instance;
	}
};

Cursor Cursor::instance;		// static member data 는 외부 선언 필요.

int main() {
	std::cout << "=============" << std::endl;
	//Cursor& c1 = Cursor::get_instance();
}





