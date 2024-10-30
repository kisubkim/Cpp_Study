/*

	정리

		Design Pattern의 핵심
			1. 공통성과 가변성의 분리
				=> 변하지 않은 코드에서 변하는 것 분리
				=> template method, factory method
				=> stataegy pattern,
				=> policy base design

		~	2. 재귀적인 포함을 위한 공통의 기반 클래스
				=> Folder는 File 뿐 아니라 Folder 자신도 보관
				=> Foder와 File은 공통의 기반 클래스
				=> composite : 재귀적 포함을 사용한 복합객체 만들기
				=> Decorator : 재귀적 포함을 사용한 객체에 기능 추가

			3. 간접층의 도입
				=> 다양한 문제를 해결하기 위해 중간층 (간접층)을 도입해서 해결.
				=> 왜? 어떤의도로 간접층을 사용하는가

				// 사용자 =============== tack ================> list
											--> 의도 : Interface의 변경. Adapter Pattern

				// 사용자 ============= TCPServer ===============> Socket, IPAddress
											--> 의도 : 복잡한 절차를 단순화하는 하나의 인터페이스. facade

				// 사용자 ============   MP3    =================> IMP3
											--> 의도 : 구현과 추상의 독립된 update. Bridge

				// 사용자 ============ BrightCommand =================> m.set_brightness(20)
											--> 의도 : undo 등의 기능을 구현하기 위해 필요한 데이타 저장. Command Pattern

				// 사용자 ============ ZipDecorator ===========> FileStream
											-- 의도 : 기능의 추가 (중첩, 원본에 대한 접근 허용). Decorator Pattern

				// 사용자 ============ Calc  =============> 원격지 서버
											-- 의도 : 다양한 의도를 가진 대신 사용한는 객체. "Proxt"

*/