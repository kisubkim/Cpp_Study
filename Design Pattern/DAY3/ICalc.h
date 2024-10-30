#pragma once


// Proxy ��ü�� ������ ���� ��� (reference counting)���� ���� �Ѵٸ�
// ���� ��� �Լ����� Interface�� �־����.


/*
	�پ��� ������ �����, �ش� ������ PRoxy �� ����ٰ� �� ��
	Proxy �� ����, Add, Sub �̸��� �޶������� ������� �Լ��� ������.
	�׷��ϱ� ������� �Լ��� ������ Interface�� �ϴ°� ����!

*/

struct IRefCount {
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual ~IRefCount() {}
};

struct ICalc : public IRefCount {
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

ICalc* load_proxy() {
	// 1. DLL load
	void* addr = ec_load_module("CalcProxy.dll");	// Linux : dlopen(), windows : LoadLibrary()

	// 2. DLL ���� ��ӵ� �Լ� ("create") �� ã��.
	using FP = ICalc * (*)();		// �Լ� ������ Ÿ��
	FP f = (FP)ec_get_function_address(addr, "create");	// Linux : dlsym(), windows : GetProcAddress()

	// 3. ��ӵ� �Լ��� ȣ���ؼ� Proxy �� �����ؼ� ��ȯ.
	return f();
}

// �Ʒ�ó�� �ص� ������ �� �� ������...���߿� �ѹ� Ȯ���� ����.
ICalc* load_prox2() {
	return reinterpret_cast<ICalc*>(GetProcAddress((HMODULE)reinterpret_cast<void*>(LoadLibraryA("CalcProxy.dll")), "create")());
}