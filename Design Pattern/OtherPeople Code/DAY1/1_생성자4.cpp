class Animal
{
 public:   // a, b모두 가능
// private:  // a, b 모두 에러
// protected:  //a 만 에러 b는 가능 파생클래스 생성만 가능하게 하고 싶다 !
	Animal() {}
};
class Dog : public Animal
{
public:
	Dog() {}
};
int main()
{
	// 다음중 에러를 모두 골라 보세요
	Animal a;
	Dog    d;
}



