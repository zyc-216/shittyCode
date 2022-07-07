#pragma once
namespace my {
	template<typename T>
	class unique_ptr {
	public:
		unique_ptr(T* _ptr = nullptr) : ptr(_ptr) {};
		~unique_ptr() { delete ptr; }

	public:
		//ɾ�����������캯���Ϳ�����ֵ��һ��ĸ�ֵ����������unique
		unique_ptr(const unique_ptr& ) = delete;
		unique_ptr& operator=(const unique_ptr&) = delete;
		//�ƶ����캯��
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