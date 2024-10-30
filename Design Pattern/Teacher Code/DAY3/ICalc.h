// ICalc.h
#pragma once

// Proxy ��ü�� ������ ���� ���(reference counting) ����
// �����Ѵٸ�
// ���� ��� �Լ����� �������̽��� �־�� �մϴ�.

// �پ��� ������ �����, �ش� ������ Proxy �� ����ٰ� �Ҷ�
// Proxy �� ����, Add, Sub �̸��� �޶�������
// ������� �Լ��� �����մϴ�.
// ������� �Լ��� ������ �������̽���!!

struct IRefCount
{
	virtual void AddRef() = 0;
	virtual void Release() = 0;

	virtual ~IRefCount() {}
};

struct ICalc : public IRefCount
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

/*
struct IMotorServerProxy : public IRefCount
{
	// ���ͼ����� Proxy �Լ�
};
*/



// Proxy Update �� ��Ģ
// 1. DLL �� �̸��� �����ϸ� �ȵ˴ϴ�.("CalcProxy.dll ����")
// 2. DLL �ȿ� "create" �� �־�� �մϴ�.

ICalc* load_proxy()
{
	// #1. DLL �� load �մϴ�.
	void* addr = ec_load_module("CalcProxy.dll");
	// linux : dlopen()   windows : LoadLibrary()

// #2. DLL ���� ��ӵ� �Լ�("create") �� ã���ϴ�.
	using FP = ICalc * (*)(); // �Լ� ������ Ÿ��
	// typedef ICalc*(*FP)()

	FP f = (FP)ec_get_function_address(addr, "create");
	// linux : dlsym()   windows : GetProcAddress()

// #3. ��ӵ� �Լ��� ȣ���ؼ� Proxy �� �����ؼ� ��ȯ
	return f();  // DLL ���ο��� new Calc;
}
