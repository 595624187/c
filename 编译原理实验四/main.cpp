#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<string>
#include<cstdio>
#define MAX 100
using namespace std;
//�������ȼ�(ע��Ĭ�ϲ����������ȼ���ߣ����䲻��Ҫ��ջ����ջ�Ķ��������)
/*
������
2*(4+15/3)=18#
*/
map<char,int> p;
e
struct Node{
	double num; //������
	char op;    //������
	bool flag;  //true��ʾ��������false��ʾ������
};

typedef struct Node node;
stack<node> s;  //������ջ
queue<node> q;  //��׺���ʽ����

void change(string str){
	node temp;
	for (int i = 0; i < str.length();){
		 if (str[i] == '('){//���������ţ�������ջ
			temp.flag = false;
			temp.op = str[i];
			s.push(temp);
			i++;
		}else if (str[i] == ')'){//���������ţ�ִ�г�ջ�������������׺���ʽ��ֱ����������������
			while (!s.empty() && s.top().op != '('){
				q.push(s.top());
				s.pop();
			}
			s.pop();        //pop������
			i++;
		}else if (str[i] >= '0'&&str[i] <= '9'){	//���������
			temp.flag = true;
			temp.num = str[i] - '0';
			i++;                    //����һλ,��Ϊ���ֲ�һ���Ǹ�λ��
			while (i < str.length() && str[i] >= '0'&&str[i] <= '9'){
				temp.num = temp.num * 10 + (str[i] - '0');
				i++;
			}
			q.push(temp);           //�����������׺���ʽ
		}else{
			//��������������������������ȼӴ��ڻ���ڸ��������ջ��Ԫ�أ�Ȼ�󽫸��������ջ
			temp.flag = false;
			while (!s.empty() && p[s.top().op]>=p[str[i]]){
				q.push(s.top());
				s.pop();
			}
			temp.op = str[i];
			s.push(temp);
			i++;
		}
	}
	//��ջ��ʣ���������ε�����׺���ʽ
	while (!s.empty()){
		q.push(s.top());
		s.pop();
	}
}

int main(void)
{
	node cur;
	string str;
	p['+'] = p['-'] = 1;//ͨ��hashmap��ֵ
	p['*'] = p['/'] = 2;
	cout<<"�������������ʽ:"<<endl;
	cin >> str;
	change(str);
	while (!q.empty()){
		cur = q.front();
		if (cur.flag == true) cout << cur.num<<" ";
		else cout << cur.op<<" ";
		q.pop();
	}
	return 0;
}
