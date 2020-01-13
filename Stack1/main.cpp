#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//链表节点表示
typedef struct Node{
	char data;
	struct Node*  next;
}Node,*NodePtr;
//栈链表表示
typedef struct {
	NodePtr top;
	NodePtr bot;
	int size;
}stack;
//初始化栈
void initStack(stack&s) {
	s.top = (NodePtr)malloc(sizeof(Node));
	if ( s.top ==NULL) {
		printf("分配失败");
		return;
	}
	s.bot = s.top;
	s.size = 0;
	s.top->next = NULL;
}
//入栈
void Push(stack&s, char e) {
	NodePtr p = (NodePtr)malloc(sizeof(Node));
	p->data = e;
	p->next = s.top;
	s.top = p;
	s.size++;
}
//出栈
char Pop(stack &s) {
	NodePtr p;
	if (s.top == s.bot)
	{
		printf("表空");
	}
	p = s.top;
	char e = p->data;
	s.top = s.top->next;
	free(p);
	s.size--;
	return e;
}
//判断栈是否为空
bool emptyStack(stack &s) {
	if (s.bot==s.top)
		return 1;
	return 0;
}
//队列链表表示
typedef struct {
	NodePtr front, rear;}Queue;
//队列的初始化
void initqueue(Queue &s) {
	NodePtr p = (NodePtr)malloc(sizeof(Node));
	if (p == NULL){printf("创建失败！");return;}
	s.front =s.rear=p ;
	s.rear->next = NULL;
}
//入队列
void Enque(Queue &s, char e) {
	NodePtr p = (NodePtr)malloc(sizeof(Node));
	p->data = e;
	p->next = NULL;
	s.rear->next = p;
	s.rear = p;
}
//出队列
char Deque(Queue &s) {
	NodePtr p;
	char c;
	if (s.front == s.rear) {
		printf("表空！");
	}
	p = s.front->next;
	c = p->data;
	s.front->next = p->next;
	if (p == s.rear) {
		s.rear = s.front;
	}
	free(p);
	return c;
}
//判断队列为空
bool emptyque(Queue&s) {
	if (s.front == s.rear)
		return 1;
	return 0;
}
//打印队列
void Fri(Queue s) {
	char ch;
	while (!emptyque(s))
	{
		ch = Deque(s);
		switch (ch) {
		case 't':printf("天");break;
		case 'd':printf("地");break;
		case 's':printf("上");break;
		case 'a':printf("一个");break;
		case 'e':printf("鹅");break;
		case 'z':printf("追");break;
		case 'g':printf("赶");break;
		case 'x':printf("下");break;
		case 'n':printf("蛋");break;
		case 'i':printf("恨");break;
		default:break;

		}

	}
}
//输入魔王语言函数
void masterLanguage(stack&s) {
	stack temp;
	char ch;
	initStack(temp);
	printf("请输入你的魔王语言：");
	char p[200] ;
	scanf("%s", p);
	for (int i = 0;i < strlen(p);i++) {
		if (p[i] == '(')
			Push(temp, '(');
		else if(p[i] == ')')
			Pop(temp);
	}
	if (!emptyStack(temp))printf("您输入的括号不匹配！" );
	//倒置输入栈
	for (int i = 0;i <= strlen(p) - 1 ;i++) {
		Push(s, p[i]);
	}
}
//处理括号逆转规则函数
void reverse(stack&s,stack&s2) {
	char e, e1,t;
	stack s1;
	while (!emptyStack(s)) {
		 e = Pop(s);
		if (e == '(') {
			e1 = Pop(s2);
			while (e!= ')') {
				e = Pop(s2);
				Push(s1, e);
			}
			Pop(s1);

			while (!emptyStack(s1))
			{
				Push(s, e1);
				e = Pop(s1);
				Push(s, e);
			}
			Push(s2, e1);

		}
		//前面在栈尾，后面在栈顶
		else Push(s2, e);
	}
}
//处理规则1函数
void Tran(stack&s) {
	Queue q;
	initqueue(q);
	while (!emptyStack(s)) {
		char e = Pop(s);
		if (e == 'A') {
			Enque(q, 's');
			Enque(q, 'a');
			Enque(q, 'e');
		}
		else if (e == 'B') {
			Enque(q, 't');
			Enque(q, 's');
			Enque(q, 'a');
			Enque(q, 'e');
			Enque(q, 'd');
			Enque(q, 's');
			Enque(q, 'a');
			Enque(q, 'e');
		}
		else
			Enque(q, e);
	}
	Fri(q);
}
int main() {
	stack sf, st;
	initStack(sf);
	initStack(st);
	masterLanguage(sf);
	reverse(sf,st);
	printf("翻译后的语言是：\n");
	Tran(st);
	printf("\n");
	system("pause");
	return 0;
}
