class Animal
{
//public:	
//private:
protected:
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
	Animal a;		// 1
	Dog    d;		// 2

	// public이니까 둘다 OK
	// Animal의 public을 private로 만들면 1, 2 모두 error
	// protected 로 변경하면 1은 error, 2는 OK

	// protected의 의도는 나는 호출할 수 없지만, 파생클래스는 호출이 가능
	// protected constructor의 의도는 나는 생성할 수 없지만, 너는 생성하게 해줄께!

	/*
	  protected 생성자 의도
		-> 자신은 만들 수 없지만 (추상적 존재, 개념)
		-> 파생 클래스는 만들 수 있도록 (구체적, 개념)

		만약 동물, 개가 있다고 해보면...
		동물 객체는 현실세계에 존재하지 않음. (추상적 개념)
		하지만 개는 현실세계에 존재함. (구체적 개념)
		즉, 개념적인 내용(abstract)은 protected constructor 사용하는게 좋음.ㄴ
	*/
}



