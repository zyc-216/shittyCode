#pragma once

#include <iostream>
using namespace std;


//�򵥵������ڴ��
class A
{
public:
	A(int i = 1) :a(i) { cout << "ctor" << endl; };

	void* operator new(size_t size)
	{
		A* p;
		if (nullptr == freePtr && numNode) //���ڴ�س���������������һ��һ����С���ڴ�أ�ֻ���������ڴ�ص������ַ�ϲ�����,������������
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
	static int numNode; //�ڵ����
	static A* freePtr; //��ʼ��Ϊ��ָ��
};

//��̬��Ա��ʼ��

int A::numNode = 0; //Ĭ�Ͻڵ���Ϊ0
void A::getNodeNum(size_t size) //��ʼ���ڵ����
{
	numNode = size;
}
A* A::freePtr = nullptr;