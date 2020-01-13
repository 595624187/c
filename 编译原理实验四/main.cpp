#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<string>
#include<cstdio>
#define MAX 100
using namespace std;
//设置优先级(注意默认操作数的优先级最高，即其不需要进栈，进栈的都是运算符)
/*
用例：
2*(4+15/3)=18#
*/
map<char,int> p;
e
struct Node{
	double num; //操作数
	char op;    //操作符
	bool flag;  //true表示操作数，false表示操作符
};

typedef struct Node node;
stack<node> s;  //操作符栈
queue<node> q;  //后缀表达式队列

void change(string str){
	node temp;
	for (int i = 0; i < str.length();){
		 if (str[i] == '('){//遇到左括号：将其入栈
			temp.flag = false;
			temp.op = str[i];
			s.push(temp);
			i++;
		}else if (str[i] == ')'){//遇到右括号：执行出栈操作，输出到后缀表达式，直到弹出的是左括号
			while (!s.empty() && s.top().op != '('){
				q.push(s.top());
				s.pop();
			}
			s.pop();        //pop左括号
			i++;
		}else if (str[i] >= '0'&&str[i] <= '9'){	//如果是数字
			temp.flag = true;
			temp.num = str[i] - '0';
			i++;                    //后移一位,因为数字不一定是个位数
			while (i < str.length() && str[i] >= '0'&&str[i] <= '9'){
				temp.num = temp.num * 10 + (str[i] - '0');
				i++;
			}
			q.push(temp);           //操作数进入后缀表达式
		}else{
			//遇到其他运算符：弹出所有优先加大于或等于该运算符的栈顶元素，然后将该运算符入栈
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
	//将栈中剩余内容依次弹出后缀表达式
	while (!s.empty()){
		q.push(s.top());
		s.pop();
	}
}

int main(void)
{
	node cur;
	string str;
	p['+'] = p['-'] = 1;//通过hashmap赋值
	p['*'] = p['/'] = 2;
	cout<<"请输入算术表达式:"<<endl;
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
