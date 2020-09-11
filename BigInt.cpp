
#include "bigint.h"

int main() {
	BigInt bt(25),
	BigInt::++bt;
	cout << bt << endl;
	return 0;
}
/*
int main() {
	BigInt bt1(25),bt2(12),bt;
	//bt1.LoadData(4);
	//bt2.LoadData(4);
	//cout << (bt1 == bt2 )<< endl;
	cout << "bt1="<<bt1<<endl;
	//bt1.ShowData();
	cout << "bt2=";
	bt2.ShowData();
	//cout << "big.size()="<<big.size() << endl;
	//bt.ADD(bt, bt1, bt2);
	//cout << "bt=bt1+bt2=";
	//bt.ShowData();
	//bt.SUB(bt, bt1, bt2);

	BigInt::SUB(bt, bt1, bt2);
	cout <<"bt="<< bt << endl;
	getchar();
	return 0;
}

/*
void Test_seqlist() {
	Seqlist<unsigned int> list;
	for (int i = 1; i <= 20; i++) {
		list.push_front(i);
	}
	for (int i = 1; i <= 20; i++) {
		cout<<list[i]<<" ";
	}
	cout << list.back ()<< endl;
	
}
int main() {
	Test_seqlist();
	getchar();
	return 0;
}*/
