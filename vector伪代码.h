#pragma once
#include <iostream>

using namespace std;
//alloc是一个类，实现多条内存池，当容器内元素创建时，
//typedef data_alloc<value_size,alloc>=data_allocator
//当容器内元素申请内存时，使用data_allocator::allocate 返回内存给内存池时，data_allocator::reallocate
//元素创建时，用全局函数construct,元素销毁时，deconstruct
//任何涉及容器内元素的内存问题，都用到allocator，不同容器申请内存规则不同，比如vector即使push_back一个元素
//当size=capaci，vector本身会申请1.5倍或者2倍，allocator也要满足它，而list申请一个元素不会出现这种情况
//所有容器内元素的内存变化都由一个分配器类的静态函数来分配，即所有元素，不管大小，属于哪个容器，都公用一个内存池
// 
//至于迭代器，实际上是一种智能指针，里面有一根指向容器内元素的指针，重载一些++，--，==之类的操作符
//所有对元素的操作，包括一些成员函数返回值都是迭代器类型，每种容器的迭代器都不一样
//猜测：迭代器虽然是智能指针，但是迭代器失效时，并不会释放掉内存，内存的释放是由allocator做的，应该没有delete
//即使delete，也应该重写了operator delete，里面并没有free