#pragma once
namespace my {
	template<typename T>
	class unique_ptr {
	public:
		unique_ptr(T* _ptr = nullptr) : ptr(_ptr) {};
		~unique_ptr() { delete ptr; }

	public:
		//删除掉拷贝构造函数和拷贝赋值和一般的赋值操作，保持unique
		unique_ptr(const unique_ptr& ) = delete;
		unique_ptr& operator=(const unique_ptr&) = delete;
		//移动构造函数
		unique_ptr(unique_ptr&& unique_ptr1) :ptr(unique_ptr1.ptr) {
			unique_ptr1.ptr = nullptr;
		}

	public:
		T*& get() { return ptr; }
		T& operator*() const { return *ptr; }
		T*& operator->() const { return ptr; }
		operator bool() const { return ptr; }
	private:
		T* ptr;
	};
}