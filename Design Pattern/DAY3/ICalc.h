#pragma once


// Proxy 객체의 수명을 참조 계수 (reference counting)으로 관리 한다면
// 참조 계수 함수들은 Interface에 있어야함.


/*
	다양한 서버를 만들고, 해당 서버의 PRoxy 를 만든다고 할 때
	Proxy 에 따라, Add, Sub 이름은 달라지지만 참조계수 함수는 동일함.
	그러니까 참조계수 함수는 별도의 Interface로 하는게 좋음!

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

	// 2. DLL 에서 약속된 함수 ("create") 를 찾음.
	using FP = ICalc * (*)();		// 함수 포인터 타입
	FP f = (FP)ec_get_function_address(addr, "create");	// Linux : dlsym(), windows : GetProcAddress()

	// 3. 약속된 함수를 호출해서 Proxy 를 생성해서 반환.
	return f();
}

// 아래처럼 해도 동작은 할 것 같은디...나중에 한번 확인해 보자.
ICalc* load_prox2() {
	return reinterpret_cast<ICalc*>(GetProcAddress((HMODULE)reinterpret_cast<void*>(LoadLibraryA("CalcProxy.dll")), "create")());
}