#pragma once
#include "Sqlist.h"

class BigInt;
ostream& operator<<(ostream &out, const BigInt &bt);

class BigInt {
	friend ostream& operator<<(ostream &out, BigInt &bt);
public:
	BigInt(u_long data=0);
public:
	void LoadData(int sz);
	void ShowData();
	void push_back(const u_char &x);
	size_t size();
public:
	//¼Ó
	static u_char AddItem(u_char a, u_char b, u_char &cnt);
	static void ADD(BigInt &bt, BigInt &bt1, BigInt &bt2);
	//¼õ
	static u_char  SUBItem(u_char a, u_char b, u_char &cnt);
	static void SUB(BigInt &bt, BigInt &bt1, BigInt &bt2);
	//³Ë
	static void MUL(BigInt &bt, BigInt &bt1, BigInt &bt2);
	//³ý
	static void DIV(BigInt &bt, BigInt &bt1, BigInt &bt2);
public:
	bool operator<( BigInt &bt);
	bool operator<=(BigInt &bt);
	bool operator>( BigInt &bt);
	bool operator>=(BigInt &bt);
	bool operator==(BigInt &bt);
	bool operator!=(BigInt &bt);
	BigInt& operator++();
	BigInt operator++(int);
private:
	Seqlist<u_char> big;
};