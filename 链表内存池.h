#pragma once

#include <iostream>
using namespace std;


//简单的链表内存池
class A
{
public:
	A(int i = 1) :a(i) { cout << "ctor" << endl; };

	void* operator new(size_t size)
	{
		A* p;
		if (nullptr == freePtr && numNode) //若内存池超出，会重新申请一个一样大小的内存池，只不过两个内存池低虚拟地址上不连续,单个池子连续
		{
			freePtr =reinterpret_cast<A*>(new char[sizeof(A) * numNode]);
			for (p = freePtr; p < freePtr + numNode; ++p)
			{
				p->next = p + 1;
			}
			p->next = nullptr;
		}
		p = freePtr;
		freePtr = freePtr->next;
		return p;
		//return static_cast<void*>(p);
	}
	void operator delete(void* p, size_t size)
	{
		reinterpret_cast<A*>(p)->next = freePtr;
		freePtr = reinterpret_cast<A*>(p);
	}

public:
	A* next;
	int a;

public:
	static void getNodeNum(size_t);
	static int numNode; //节点个数
	static A* freePtr; //初始化为空指针
};

//静态成员初始化

int A::numNode = 0; //默认节点数为0
void A::getNodeNum(size_t size) //初始化节点个数
{
	numNode = size;
}
A* A::freePtr = nullptr;