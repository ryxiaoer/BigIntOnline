#include "bigint.h"

ostream& operator<<(ostream &out, BigInt &bt) {
	for (u_long i = bt.size(); i >= 1; i--) {
		out << (int)bt.big[i];
	}
	return out;
}
void BigInt::LoadData(int sz) {
	for (int i=1; i <= sz; i++) {
		big.push_back(rand()%10);
	}
}
/////////////////////////////////////////////////////////////////////
BigInt::BigInt(u_long data) {
	u_long i = 1;
	while (data >= 10) {
		push_back(data % 10);
		data /= 10;
	}
	push_back(data);
}
//////////////////////////////////////////////////////////////////////
void BigInt:: ShowData() {
	for (int i = big.len(); i >= 1; i--) {
		std::cout << (int)big[i] ;
	}
	std::cout << endl;
}
void BigInt::push_back(const u_char &x) {
	big.push_back(x);
}
size_t BigInt::size() {
	return big.len();
}
///////////////////////////////符号重载/////////////////////////////////////
bool BigInt:: operator<(BigInt &bt) {
	if (size()<bt.size()) return true;
	else if(size()>bt.size()) return false;
	else {
		for (u_long i = bt.size(); i >=1; i--){
			if (big[i] > bt.big[i])
				return false;
			else if (big[i] < bt.big[i])
				return true;
		}
		return false;//如果相等
	}
}
bool BigInt:: operator>(BigInt &bt) {
	if (size() > bt.size()) return true;
	else if (size() < bt.size()) return false;
	else {
		for (u_long i = bt.size(); i >= 1; i--) {
			if (big[i] < bt.big[i])
				return false;
			else if (big[i] >bt.big[i])
				return true;
		}
		return false;//如果相等
	}
}
bool BigInt:: operator==(BigInt &bt) {
	if (size() != bt.size()) return false;
	else {
		for (u_long i = 1; i < size(); i++) {
			if (big[i] != bt.big[i])
				return false;
		}
		return true;
	}
}
bool BigInt:: operator!=(BigInt &bt) {
	if (*this == bt) return false;
	else return true;
}
BigInt& BigInt:: operator++() {
	u_long i = 1;
	u_char cnt = 1;
	while (cnt > 0 && i <= size());
	{
		(*this).big[i] = AddItem((*this).big[i], 0, cnt);
		i++;
	}
	if (cnt > 0)
		push_back(cnt);
	return *this;
}
BigInt  BigInt::operator++(int)
{
	BigInt tmp = *this;
	++*this;
	return tmp;
}
/////////////////////////////////////////////////////////////////////////////////////
//ADD
 u_char  BigInt::AddItem(u_char a, u_char b, u_char &cnt) {
	//实现两个字符的相加
	u_char sum= a + b + cnt;
	cnt = 0;
	if (sum >= 10) {
		sum -= 10;
		cnt = 1;
	}
	return sum;
}
void BigInt:: ADD(BigInt &bt, BigInt &bt1,  BigInt &bt2) {
	u_long i =1, j = 1;
	u_char sum = 0, cnt = 0;
	while (i <= bt1.size() && j <= bt2.size()) {
		sum = AddItem(bt1.big[i], bt2.big[j], cnt);
		bt.push_back(sum);
		i++;
		j++;
	}
	while (i <= bt1.size()) {
		sum = AddItem(bt1.big[i],0, cnt);
		bt.push_back(sum);
		i++;
	}
	while (j <= bt2.size()) {
		sum = AddItem(0, bt2.big[j], cnt);
		bt.push_back(sum);
		j++;
	}
	if (cnt == 1)
		bt.push_back(cnt);
	return;
}
//SUB
u_char  BigInt::SUBItem(u_char a, u_char b, u_char &bor) {
	//实现两个字符的相减
	u_char res;
	if (a >= b + bor) {
		res = a - b- bor;
		bor = 0;
	}
	else {
		res = a + 10 - b - bor;
		bor = 1;
	}
	return res;
}
void BigInt::SUB(BigInt &bt, BigInt &bt1, BigInt &bt2) {
	bt.big.clear();
	if (bt1 < bt2) return;
	if (bt1 == bt2) { 
		BigInt tmp(0);
		bt = tmp;
		return; 
	}
	u_long i = 1, j = 1;
	u_char res = 0, bor = 0;
	while (i <= bt1.size() && j <= bt2.size()) {
		res = SUBItem(bt1.big[i], bt2.big[j], bor);
		bt.push_back(res);
		i++;
		j++;
	}
	while (i <= bt1.size()) {
		res = SUBItem(bt1.big[i], 0, bor);
		bt.push_back(res);
		i++;
	}
	return;
}