/*
	Design Pattern의 핵심
		1. 변하지 않은 코드에서 변하는 것을 분리하는 것!!! (교제 35page부터 관련 내용이 나옴)
			방법 1. 변하는 것을 가상함수로 분리'
			  => 파생 클래스를 만들어서 가상함수 override를 통한 변경
			  => template method 패턴

			  => NumEdit가 "Edit 기능 및 VAlidation 기능 모두 포함"
			  => 다른 입력도구에서 Validation 기능을 사용할 수 없음. (왜냐면 이녀석은 Editor만 사용이 가능한 상태니까..)

			  // NumEdit e;				// e 가진 정책은 실행할 때 변경할 수 없다.
			  // AddressEdit e2;		// e의 정책이 변경된 것이 아니라 다른 정책을 가진 새로운 edit


			방법 2. 변하는 것을 다른 클래스로 분리
			  => validation 정책을 다른 클래스로
			  => interface를 먼저 설게하고 validation 클래스 작성
			  => stratege pattern

			  => Edit와 Validation 정책이 분리됨.
			  => 즉, 다른 입력도구에서도 Validation 정책을 사용할 수 있음.
			  => 또한 Validation 정책을 실행시간에 교체도 가능함.

				LimitDigitValidator v1(5);
				e.set_validator(&v1);

				... 한 5분 뒤에
				LimitDigitValidator v2(10);
				e.set_validator(&v2);

				요렇게 하면 실시간으로 동작을 변경할 수 있음.


		결론 : Edit 예제는 template method 보다 stratege 가 좋음.

		그런데, 도형 편집기의 draw/draw_imp 관계는 Rect를 어떻게 그릴지는 
		실행할 때 변경될 필요 없다. 또한 다른 클래스에서 사용할 필요 없다.
		=> 요럴 때는 Rect가 그리는 방법을 소유(멤버함수)하는 것이 좋음.
		=> 멤버 함수는 "private 멤버 데이터 접근"을 할 수 있음.

*/