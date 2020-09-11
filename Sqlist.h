#pragma once

#include "Common.h"

////////////////////////////////////声明/////////////////////////////////
template<class Type>
class Seqlist {
public:
	Seqlist(int sz = SEQLIST_DEFAULT_SIZE);
	~Seqlist();
public:
	typedef Type& reference;
	typedef const Type& const_reference;
public:
	bool isFull()const;
	bool isEmpey()const;
	void push_back(const Type &x);
	void push_front(const Type &x);
	void pop_back();
	void pop_front();
	reference operator[](int pos);
//	const_reference operator[](int pos);
	reference front();
	reference back();
	const_reference back()const;
	const_reference front()const;
	size_t len()const;
	void reverse();
	void clear();
	void sort();
	int find(const Type &key);
	void erase(const Type &key);
public:
	Seqlist& operator=(Seqlist<Type> &st);
	Seqlist& operator+(Seqlist<Type> &st);
	Seqlist& operator-(Seqlist<Type> &st);
	bool  operator==(Seqlist<Type> &bt);
	Seqlist& operator++();
	Seqlist& operator++(int);
	Seqlist& operator--();
	Seqlist& operator--(int);
protected:
	bool _Inc();
private:
	enum {SEQLIST_DEFAULT_SIZE=20}; //顺序表默认大小
private:
	Type *base;
	size_t capacity;
	size_t size;
};
//////////////////////////////顺序表的实现///////////////////////////////
template<class Type>
Seqlist<Type>::Seqlist(int sz){
	capacity = sz > SEQLIST_DEFAULT_SIZE ? sz : SEQLIST_DEFAULT_SIZE;
	base = new Type[capacity + 1];
	memset(base, 0, sizeof(Type)*(capacity + 1));
	size = 0;
}
template<class Type>
Seqlist<Type>::~Seqlist() {
	delete []base;
	base = nullptr;
	capacity = size = 0;
}
template<class Type>
bool Seqlist<Type>::isFull() const {
	return size >= capacity;
}
template<class Type>
bool Seqlist<Type>::isEmpey()const {
	return 0 == size;
}
//尾插
template<class Type>
void Seqlist<Type>::push_back(const Type &x) {
	if (isFull()) {
		//扩容或打印错误
		ERR_EXIT("push_back");
	}
	base[++size] = x; //0位置不放置数据,放符号
	//cout << size << " ";
}
template<class Type>
void Seqlist<Type>::push_front(const Type &x) {
	if (isFull() && !_Inc()) {
		//扩容或打印错误
		ERR_EXIT("push_front");
	}
	for (size_t i = size; i >= 1; i--) {
		base[i+1] = base[i];
	}
	base[1] = x;
	size++;
}
template<class Type>
void Seqlist<Type>::pop_back() {
	if (isEmpey())
		ERR_EXIT("pop_back");
	size--;
}
template<class Type>
void Seqlist<Type>::pop_front() {
	if (isFull() && !_Inc()) {
		//扩容或打印错误
		ERR_EXIT("push_front");
	}
	for (size_t i = 1; i < size; i++) {
		base[ i ] = base[i+1];
	}
	size--;
}
template<class Type>
typename Seqlist<Type>::reference  Seqlist<Type>::operator[](int pos) {
	assert(pos >= 1 && pos<=size); //0不存数据
	return base[pos];
}
template<class Type>
size_t Seqlist<Type>:: len()const {
	return size;
}
//取表头元素
template<class Type>
typename Seqlist<Type>::reference Seqlist<Type>::front() {
	if (isEmpey())
		ERR_EXIT("front");
	return base[1];
}
template<class Type>
typename Seqlist<Type>::reference Seqlist<Type>::back() {
	if (isEmpey())
		ERR_EXIT("back");
	return base[size];
}
//转置
template<class Type>
void Seqlist<Type>::reverse() {
	if (size <= 1)
		return;
	size_t start = 1, end = size;
	while (start < end) {
		Type tmp = base[start];
		base[start] = base[end];
		base[end] = tmp;
		start++;
		end--;
	}
}
template<class Type>
void Seqlist<Type>::clear() {
	size = 0;
}

template<class Type>
Seqlist<Type>& Seqlist<Type>::operator=( Seqlist<Type>& st){
	if (this != &st) {
		//深拷贝
		if (capacity < st.len()) {
		//扩容
			Type* new_base = new Type[st.capacity + 1];
			delete[]base;
			//base = new Type[st.capacity + 1]; //考虑到内存申请空间异常可以先new_base,否则直接申请失败可能会丢失原来的数据
			base = new_base;
			capacity = st.capacity + 1;
		}
		memcpy(base, st.base, sizeof(Type)*(st.size+1));
		size = st.size + 1;
	}
	return *this;
}
template<class Type>
bool Seqlist<Type>::_Inc() {
	Type* new_base;
	try
	{
		new_base = new Type[capacity * 2 + 1];
	}
	catch (std::bad_alloc)
	{
		std::cout << "Out of Memory.";
		return false;
	}
	memset(new_base, 0, sizeof(Type)*(capacity * 2 + 1));
	memcpy(new_base, base, sizeof(Type)*(capacity + 1));
	capacity *= 2;
	delete[]base;
	base = new_base;
	return true;

}
