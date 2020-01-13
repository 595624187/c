#include<String>
#include<iostream>

using namespace std;
#define MAXS 100
using namespace std;
string CHANGE;//终结符集合
int N;//NFA边数
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
	string first;  //头
	string change;//边
	string last;   //尾
};

//查找一个节点的闭包
void eclouse(char c, string &t, edge b[]) {
	int k;
	for (k = 0; k < N; k++) {                //遍历每一条边，找到要求闭包的节点
		if (c == b[k].first[0])             //找到某条边的起点为目标节点
			if (b[k].change == "*") {       //如果转移条件为空(yibuxiu)
				if (t.find(b[k].last) > t.length())//如果集合String中没有这个节点，将其加入
					t += b[k].last;
				eclouse(b[k].last[0], t, b);
			}
	}
}

int main() {
	edge *b = new edge[MAXS];
	string jh[MAXS], endnode, ednode, sta;
	int i;
	cout << "请输入NFA各边信息（起点 条件[空为*] 终点），以#结束：" << endl;
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
