#include<String>
#include<iostream>

using namespace std;
#define MAXS 100
using namespace std;
string CHANGE;//�ս������
int N;//NFA����
/*
1 * 2
6 * 2
3 * 8
4 * 7
1 a 5
2 a 3
1 a 4
5 * 6
#
*/
struct edge {
	string first;  //ͷ
	string change;//��
	string last;   //β
};

//����һ���ڵ�ıհ�
void eclouse(char c, string &t, edge b[]) {
	int k;
	for (k = 0; k < N; k++) {                //����ÿһ���ߣ��ҵ�Ҫ��հ��Ľڵ�
		if (c == b[k].first[0])             //�ҵ�ĳ���ߵ����ΪĿ��ڵ�
			if (b[k].change == "*") {       //���ת������Ϊ��(yibuxiu)
				if (t.find(b[k].last) > t.length())//�������String��û������ڵ㣬�������
					t += b[k].last;
				eclouse(b[k].last[0], t, b);
			}
	}
}

int main() {
	edge *b = new edge[MAXS];
	string jh[MAXS], endnode, ednode, sta;
	int i;
	cout << "������NFA������Ϣ����� ����[��Ϊ*] �յ㣩����#������" << endl;
	for (i = 0; i < MAXS; i++) {
		cin >> b[i].first;
		if (b[i].first == "#") break;
		cin >> b[i].change >> b[i].last;
	}
	N = i;
	string I = "5";
	string result = I;
	for (int j = 0; j < I.length(); j++) {
		eclouse(I[j], result, b);
	}

	cout<<"e-closure(I):"<<result<<endl;

	return 0;
}
