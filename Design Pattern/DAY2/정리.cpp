// 디자인 패턴의 핵심 #1. 공통성과 가변성의 분리
// => 변하지 않은 코드 내부의 변하는 것을 찾아서 분리하는 것



// 변하는 것을 어떻게 분리할것인가 ?

// 1. 가상함수로 분리
// => 파생 클래스를 만들어서 가상함수 override 하라는 것
// => template method, factory method


// 2. 다른 클래스로 분리
// => 클래스가 사용하는 어떤 정책을 다른 클래스로 분리하는 방법
// => strategy, policy base design

// => 정책을 담을 클래스를 어떻게 교체할것인가 ?
// strategy           : 인터페이스를 사용해서 정책 클래스 교체
// policy base design : template 인자를 사용해서 정책 클래스 교체
//						(C++ Idioms)



// 참고 : 가상함수!!
// => 프로그램에서 가끔 호출된다면 사용해도 문제 되지 않습니다.
// => 루프안에서 수천~수만번 호출되는 경우는 가상함수는 오버헤드가 큽니다.


/*
	Design Pattern의 핵심 #2. 재귀적인 포함을 사용하는 경우가 많다.
		=> Folder 는 File을 보관하지만 Folder 자신도 보관
		=> origin 객체 기능 추가 가능, 추가된 객체에 또 추가 가능.

		        [ component ]
		        /            \
		       /              \
		[ Folder ]          [ File ]
		----------------------------

		=> 핵심 : Folder 와 File 은 공통의 기반 클래스 필요
		=> 핵심 : origin 과 Decorator도 공통의 기반 클래스 필요

		즉, Composite 와 Decorator 를 그려보면 거의 비슷함.
		왜?? 어떤 의도로 재귀적 포함을 사용하는 지가 다름.

		Composite : 재귀적 포함을 사요해서 "복합객체" - 객체 여러개 보관
		Decorator : 재귀적 포함을 사용해서 객체에 "기능 추가" 
					한 개의 객체에 "동작" 추가.

		객체도 보관하고, 동작도 추가하면 좋은거 아니냐? 할 수도 있지만...
		항상 coding 에서 이야기 하는게..한번에 한 개만 제대로 하자 임. 잘 기억하자.


	Design Pattern 핵심 3. "간접층의 도입"
		5_Adapter3.cpp 에 보면 decorator 와 adapter의 차이에 대해서 적혀 있음. (전체적인 Format은 거의 동일함)
			decorator : 기능의 추가를 위해서 사용 (Interface는 동일)
			adapter   : Interface의 변경을 위해서 사용 (기능은 동일)
*/
