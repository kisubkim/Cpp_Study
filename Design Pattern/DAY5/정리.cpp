/*
	����
		#1. ���뼺�� �������� �и�
			1. ���ϴ� ���� �����Լ���
				>> template method (���������� draw/draw_imp)
				>> factory method

			2. ���ϴ� ���� �ٸ� Ŭ������ (�Ʒ� 2���� class diagram ������)
				>> strategy	: Algorithm (Edit / IValidator)
				>> state	: ��ü�� ���¿� ���� ���� ��� ����. (Charactor ����)
				>> builder	: ������ ��ü�� ���� �� ���

				>> policy base design : Algorithm �� ������ �� interface�� �ƴ� template Arg �� ����.
				                       (std::vector<int, debug_alloc<int>> v;)


		#2. ������� ������ ���ؼ� ������ ��� Ŭ���� �����
			1. composite	: ������� ������ ����ؼ� "���հ�ü" ����� ( Menu ����)
			2. decorator	: ������� ������ ����� ���� "���" �߰� (FileStream/ZipDecorator)

		#3. �������� ����
			1. adaptor	: interface�� ����
			2. bridge	: ������ �߻��� ������ update
			3. facade	: ������ ������ �ܼ�ȭ�ϴ� �ϳ��� interface ����
			4. proxy	: ������ �뵵�� "������" �����

		#4. Undo / Redo �� �����ϰ�
			1. command	: ������ ���
			2. memento	: ������ ����

		#5. ����, �뺸, �湮
			1. iterator	: ������ �ٸ� ���հ�ü�� ���� ������� ����
			2. visitor	: ���հ�ü�� ��� ��ҿ� ������ ����
			3. observer	: 1:N �� ���迡�� 1�� ���ϸ� N �� �뺸
			4. chain of responsibility	: ������ �ذ��� "���� ���� �ٸ� ��ü�� ����"

		# Design Pattern �� �뵵�� ���� 3������ �з�. (�߿������� ���� ����)
			1. ���� ���� (5��) - ��ü�� ���� �� ���
				singleton, abstract factory, factory method, builder, prototype

			2. ���� ���� 7��
				����� ���� 2��	: composit, decorator
				������ 4��		: adapter, bridge, facade, proxy
				��ü�� ����		: flyweight

			3. ���� ���� 11��
				���ϴ� �� �и� 3��	: template method, strategy, state
				����, �湮, �뺸 4��	: iterator, visitor, observer, chain of responsibility
				���, ���� 2��		: command, memento
				������ 1��			: mediator
				�����Ϸ� parser ���� �� ����ߴ� pattern 1�� (������ ���� ������) : interpret
*/