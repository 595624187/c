/*
编写程序，重载运算符“<<”和“>>”，使用户能直接输入和输出固定电话的号码。
电话号码以如下形式输入和输出： (027)xxxxxxxx
*/
#include<iostream>
#include<string.h>
using namespace std;
class Phonenum {
public:
	Phonenum(char* _n) {
		strcpy(n,_n);
	}
	friend istream &operator>>(istream &in, Phonenum &p);
	friend ostream &operator<<(ostream &out, Phonenum &p);

	char n[14];
};
istream &operator>>(istream &in, Phonenum &p) {
	in.get(p.n,1,4);
	in.get(p.n, 5, 12);
	return in;
}

ostream &operator<<(ostream &out, Phonenum &p) {

}
//(027)12345678
int main()
{
	char str[14] = ("(027)12345678");
	Phonenum a(str);
	//cin >> a;
	cout << a.n << endl;
	//system("pause");
}
