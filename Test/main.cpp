/*
��д���������������<<���͡�>>����ʹ�û���ֱ�����������̶��绰�ĺ��롣
�绰������������ʽ���������� (027)xxxxxxxx
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
