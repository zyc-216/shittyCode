#pragma once
namespace my {
	template<typename T>
	class auto_ptr {
	public:
		auto_ptr(T* _ptr = nullptr) :ptr(_ptr) {};
		~auto_ptr() { delete ptr; }

	public:
		//深拷贝
		auto_ptr(const auto_ptr& auto_ptr1) {
			ptr = new T;
			*ptr = *(auto_ptr1.ptr);
		}
		auto_ptr& operator=(const auto_ptr& auto_ptr1) {
			ptr = new T(*(auto_ptr1.ptr));
			return *this;
		}
		//移动构造函数
		auto_ptr(auto_ptr&& auto_ptr1) :ptr(auto_ptr1.ptr) {
			auto_ptr1.ptr = nullptr;
		}

	public:
		T*& get() const { return ptr; }
		T& operator*() const { return *ptr; }
		T*& operator->() const { return ptr; }
		operator bool() const { return ptr; }
	private:
		T* ptr;
	};
}
 //namespace my