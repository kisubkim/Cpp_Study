// ����
// #1. ���뼺�� �������� �и�
// 1-1. ���ϴ� ���� �����Լ���
//		=> template method ( ���������� draw/draw_imp)
//		=> factory method
// 
// 1-2. ���ϴ� ���� �ٸ� Ŭ������
//		=> strategy : �˰��� ��ü ( Edit/IValidator )
//		=> state	: ��ü ���¿� ���� ��� ���� ���� ( Character ����)
//		=> builder  : ������ ��ü�� ���鶧 ���

//		=> policy base design : �˰����� �����Ҷ� �������̽��� �ƴ� ���ø� ���ڷ�?
//				std::vector<int, debug_alloc<int>> v;

//-------------------------------------------
// #2. ������� ������ ���ؼ� ������ ��� Ŭ���� �����
// => composite : ����� ������ ����� ���հ�ü ����� ( �޴� ���� )
// => decorator : ����� ������ ����� ���� ����߰� ( FileStream, ZipDecorator)

// #3. �������� ������
// adapter : �������̽��� ����
// bridge  : ������ �߻��� ������ update
// facade  : ������ ������ �ܼ�ȭ�ϴ� �ϳ��� �������̽� ����
// proxy   : �������뵵�� "������" �����

// #4. Undo/Redo �� �����ϰ�
// command : ������ ���
// memento : ������ ����

// #5. ����, �뺸, �湮

// iterator : ������ �ٸ� ���հ�ü�� ���� ������� ����
// 
// visitor : ���հ�ü�� ��� ��ҿ� ������ ����

// observer : 1:N �� ���迡�� 1�� ���ϸ� N �� �뺸

// chain of responsibility : ������ �ذ��� "���� ���� �ٸ� ��ü�� ����"


// ������ ������ �뵵�� ���� 3������ �з� �մϴ�.(�߿������� ����)

// ���� ���� 5�� - ��ü�� ���鶧 ���
// => singleton
// => abstract factory
// => factory method
// => builder
// => prototype

// ���� ���� 7��
// ����� ���� 2�� : composite, decorator
// ������ 4�� : adapter, bridge, facade, proxy
// ��ü�� ���� : flyweight

// ���� ���� 11��
// ���ϴ� �� �и� : template method, strategy, state 
// ���� �湮, �뺸 : iterator, visitor, observer, chain of reponsibility
// ���, ���� : command, memento
// ������     : mediator 
// �����Ϸ� �ļ� ���鶧 ����ߴ� ����(������ ���� ������) : interpret 