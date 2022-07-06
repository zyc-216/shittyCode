#include "嵌入式指针内存池.h"
#include "链表内存池.h"
#include "allocator.h"
using namespace std;
//using namespace std;

void testLinkedListMemPool()
{
	A::getNodeNum(5);
	A* a1 = new A;
	A* a2 = new A(2);
	A* a3 = new A(3);
	A* a4 = new A(4);
	A* a5 = new A(5);
	//第一个内存池用完
	A* a6 = new A(6);
	A* a7 = new A(7);
	printf("%p\n%p\n%p\n%p\n", a4, a5, a6, a7);
	A* a8 = new A[2];
	A* a9 = new A(9);
	printf("%p\n%p\n", a8,a9);
}

//字符串 字符数组 字符
void test2() {
	char a[] = { 'h','e','\n','\0',};
	printf("%s", a);
	char b[] = "hello";
	printf("%s\n", b);
	string c = "hello";
	printf("%s\n",c);
	char* d = b;
	printf("%s\n", d);
	char e = 'f';
	char* f = &e;
	printf("%c\n", f);
}


int main() {

	return 0;
}