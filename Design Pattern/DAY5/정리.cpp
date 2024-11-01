/*
	정리
		#1. 공통성과 가변성의 분리
			1. 변하는 것을 가상함수로
				>> template method (도형편집기 draw/draw_imp)
				>> factory method

			2. 변하는 것을 다른 클래스로 (아래 2개는 class diagram 동일함)
				>> strategy	: Algorithm (Edit / IValidator)
				>> state	: 객체의 상태에 따라 거의 모든 동작. (Charactor 동작)
				>> builder	: 복잡한 객체를 만들 때 사용

				>> policy base design : Algorithm 을 변경할 때 interface가 아닌 template Arg 로 변경.
				                       (std::vector<int, debug_alloc<int>> v;)


		#2. 재귀적인 포함을 위해서 공통의 기반 클래스 만들기
			1. composite	: 재귀적인 포함을 사용해서 "복합객체" 만들기 ( Menu 예제)
			2. decorator	: 재귀적인 포함을 사용한 동적 "기능" 추가 (FileStream/ZipDecorator)

		#3. 간접층을 만들어가
			1. adaptor	: interface의 변경
			2. bridge	: 구현과 추상의 독립된 update
			3. facade	: 복잡한 절차를 단순화하는 하나의 interface 제공
			4. proxy	: 범용적 용도의 "대행자" 만들기

		#4. Undo / Redo 가 가능하게
			1. command	: 동작의 취소
			2. memento	: 상태의 저장

		#5. 열거, 통보, 방문
			1. iterator	: 구조가 다른 복합객체를 동일 방식으로 열거
			2. visitor	: 복합객체에 모든 요소에 연산을 수행
			3. observer	: 1:N 의 관계에서 1이 변하면 N 에 통보
			4. chain of responsibility	: 문제의 해결을 "고리에 따라 다른 객체에 전달"

		# Design Pattern 은 용도에 따라 3가지로 분류. (중요하지는 않은 내용)
			1. 생성 패턴 (5개) - 객체를 만들 때 사용
				singleton, abstract factory, factory method, builder, prototype

			2. 구조 패턴 7개
				재귀적 포함 2개	: composit, decorator
				간접층 4개		: adapter, bridge, facade, proxy
				객체의 공유		: flyweight

			3. 행위 패턴 11개
				변하는 것 분리 3개	: template method, strategy, state
				열거, 방문, 통보 4개	: iterator, visitor, observer, chain of responsibility
				취소, 저장 2개		: command, memento
				중재자 1개			: mediator
				컴파일러 parser 만들 때 사용했던 pattern 1개 (지금은 거의 사용안함) : interpret
*/