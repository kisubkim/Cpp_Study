#pragma once
#define USING_GUI

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


ICalc* load_proxy()
{
	// #1. DLL load
	void* addr = ec_load_module("CalcProxy.dll");
	// linux   : dlopen()
	// windows : LoadLibrary()

	using F = ICalc * (*)(); // �Լ� ������ Ÿ��
	// typedef ICalc*(*F)()

// #2. DLL ���� ��ӵ� �Լ� ã��
	F f = (F)ec_get_function_address(addr, "getInstance");
	// linux   : dlsym()
	// windows : GetProcAddress()

// #3. ��ӵ� �Լ��� proxy �����.
	return f();
}
