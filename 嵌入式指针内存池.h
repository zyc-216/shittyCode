#pragma once
#include <iostream>

using namespace std;

class B
{	
	B() {
		m.a = 5;
		m.b = 10;
	}//default ctor
private:
	struct member
	{
		int a;
		double b;
	};
	union 
	{
		member m;
		B* ptr;
	};
public:
	void set(int a, int b)  
	{
		m.a = a;
		m.b = b;
	}
public:
	static void* operator new(size_t size)
	{
		B* p;
		if (nullptr == freePtr)
		{
			freePtr = reinterpret_cast<B*>(::operator new(sizeOfMemPool * sizeof(B)));
			for (p = freePtr; p < freePtr + sizeOfMemPool; ++p) 
			{
				p->ptr = p + 1;
			}
			p->ptr = nullptr;
		}
		p = freePtr;
		freePtr = freePtr->ptr;
		return p;
	}
	static void operator delete(void* p,size_t size)
	{
		reinterpret_cast<B*>(p)->ptr = freePtr;
		freePtr = reinterpret_cast<B*>(p);
	}
private:
	//一旦初始化便不可更改
	static const int sizeOfMemPool;
	static B* freePtr;
};

const int B::sizeOfMemPool = 5;
B* B::freePtr = nullptr;