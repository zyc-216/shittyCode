#pragma once
#include <malloc.h>
#include <initializer_list>
namespace header3 {
	class allocator
	{
	public:
		allocator(int CHUNK = 5) { this->CHUNK = CHUNK; };
		struct s {
			s* next;
		};
	public:
		void* allocate(size_t size) {
			s* ptr;
			if (nullptr == freePtr) {
				freePtr = ptr = reinterpret_cast<s*>(malloc(size * CHUNK));
				for (auto i : { 1, 2, 3, 4, 5 }) {
					ptr->next = (s*)((char*)ptr + size);
				}
				ptr->next = nullptr;
			}
			ptr = freePtr;
			freePtr = freePtr->next;
			return ptr;
		}
	public:
		void deallocate(void* p, size_t size) {

			reinterpret_cast<s*>(p)->next = freePtr;
			freePtr = reinterpret_cast<s*>(p);
		}
		s* freePtr = nullptr;
		int CHUNK;
	};
	class A
	{
	public:
		static void* operator new(size_t size)
		{
			return Alloc.allocate(size);
		}
		static void operator delete(void* p, size_t size) {
			Alloc.deallocate(p, size);
		}
	public:
		int a;
	public:
		static allocator Alloc;
		static int b;
	};
	int A::b = 5;
	allocator A::Alloc;
	
}
