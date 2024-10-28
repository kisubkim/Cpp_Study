// edit3.cpp
// => 변하는 것을 가상함수로 분리한것 : template method 패턴
// => 변경하려면 "파생클래스 만들어서 가상함수 override" 
//    하라는 의도
// 특징 : NumEdit 가 Edit 기능과 Validation 기능을 모두 포함한다(멤버 함수)
// 
// 단점 1. 다른 클래스에서는 NumEdit 의 Validation 정책을 사용할수 없다.
//    NumEdit 만 사용(독점!!)

// 단점 2. 실행시간에 Validation 정책 변경 안됨.

// 장점 . 변하는 정책이 멤버 함수이다. private 멤버에 접근 가능하다.
//		 validate 함수 안에서 모든 멤버 접근 가능



// edit4.cpp
// => 변하는 것을 다른 클래스로 분리한것 : strategy 패턴
// => 특징 : Edit 와 Validation 정책이 다른 클래스로 분리됨
// 장점 1. Validation 정책을 "다른 클래스"에서도 사용가능
// 장점 2. 실행시간에 Validation 정책 변경 가능

// 단점 : Validator 에서는 Edit 의 멤버 접근이 어려워 진다.
//        멤버 함수가 아님.
//        validate() 함수 인자로 보낼수 밖에 없다.

// 도형편집기의 draw()/draw_imp()