// 7_객체생성정리 - 118 page
class Rect
{
};

// Design Pattern 의 핵심
//	#4. 객체를 생성하는 다양한 방법을 알아 두자.

// 객체를 만드는 방법

// 1. Rect rc;		// 수명이 정해져 있음.
					// 전역 변수 : 파괴되지 않음.
					// 지역 변수 : block 을 벗어날 수 없음.
					// => 사용자가 원하는 시점 파괴는 안됨.

// 2. Rect* rc = new Rect     => 가장 자유로운 방법
							  // 자유롭다고 해서 가장 좋은 것은 아님.

// 아래의 다양한 방법도 꼭 고려해 봐야함.
// 
// 3. Rect* rc = Rect::create()  : static 멤버 함수 사용
//								   다양한 제약을 사용할수 있다.
//					A. 오직 한개만 만들수 있게 -> 싱글톤
//					B. 속성이 동일하면 공유    => 플라이 웨이트
//				    C. 생성함수주소를 함수 인자로 전달하거나
//					   자료구조에 보관

// Design Pattern : Factory method 가 있음. - 요건 다음 시간
// Java 에서 위 3번 기술을 "static factory method" 라고 함.
// 구글에서 static factory method 검색하고 첫번째 링크 들어가보자.

// 3. Rect* rc = sample->clone();  : 복사본을 사용한 객체 생성 - Prototype
									// 견본을 먼저 만들어서 등록하고(공장)
									//	복사본을 사용한 객체 생성. (Prototype)
// 4. Rect* rc = factory.create() : 공장을 통한 객체 생성




