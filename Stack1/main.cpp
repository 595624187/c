#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����ڵ��ʾ
typedef struct Node{
	char data;
	struct Node*  next;
}Node,*NodePtr;
//ջ�����ʾ
typedef struct {
	NodePtr top;
	NodePtr bot;
	int size;
}stack;
//��ʼ��ջ
void initStack(stack&s) {
	s.top = (NodePtr)malloc(sizeof(Node));
	if ( s.top ==NULL) {
		printf("����ʧ��");
		return;
	}
	s.bot = s.top;
	s.size = 0;
	s.top->next = NULL;
}
//��ջ
void Push(stack&s, char e) {
	NodePtr p = (NodePtr)malloc(sizeof(Node));
	p->data = e;
	p->next = s.top;
	s.top = p;
	s.size++;
}
//��ջ
char Pop(stack &s) {
	NodePtr p;
	if (s.top == s.bot)
	{
		printf("���");
	}
	p = s.top;
	char e = p->data;
	s.top = s.top->next;
	free(p);
	s.size--;
	return e;
}
//�ж�ջ�Ƿ�Ϊ��
bool emptyStack(stack &s) {
	if (s.bot==s.top)
		return 1;
	return 0;
}
//���������ʾ
typedef struct {
	NodePtr front, rear;}Queue;
//���еĳ�ʼ��
void initqueue(Queue &s) {
	NodePtr p = (NodePtr)malloc(sizeof(Node));
	if (p == NULL){printf("����ʧ�ܣ�");return;}
	s.front =s.rear=p ;
	s.rear->next = NULL;
}
//�����
void Enque(Queue &s, char e) {
	NodePtr p = (NodePtr)malloc(sizeof(Node));
	p->data = e;
	p->next = NULL;
	s.rear->next = p;
	s.rear = p;
}
//������
char Deque(Queue &s) {
	NodePtr p;
	char c;
	if (s.front == s.rear) {
		printf("��գ�");
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
//�ж϶���Ϊ��
bool emptyque(Queue&s) {
	if (s.front == s.rear)
		return 1;
	return 0;
}
//��ӡ����
void Fri(Queue s) {
	char ch;
	while (!emptyque(s))
	{
		ch = Deque(s);
		switch (ch) {
		case 't':printf("��");break;
		case 'd':printf("��");break;
		case 's':printf("��");break;
		case 'a':printf("һ��");break;
		case 'e':printf("��");break;
		case 'z':printf("׷");break;
		case 'g':printf("��");break;
		case 'x':printf("��");break;
		case 'n':printf("��");break;
		case 'i':printf("��");break;
		default:break;

		}

	}
}
//����ħ�����Ժ���
void masterLanguage(stack&s) {
	stack temp;
	char ch;
	initStack(temp);
	printf("���������ħ�����ԣ�");
	char p[200] ;
	scanf("%s", p);
	for (int i = 0;i < strlen(p);i++) {
		if (p[i] == '(')
			Push(temp, '(');
		else if(p[i] == ')')
			Pop(temp);
	}
	if (!emptyStack(temp))printf("����������Ų�ƥ�䣡" );
	//��������ջ
	for (int i = 0;i <= strlen(p) - 1 ;i++) {
		Push(s, p[i]);
	}
}
//����������ת������
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
		//ǰ����ջβ��������ջ��
		else Push(s2, e);
	}
}
//�������1����
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
	printf("�����������ǣ�\n");
	Tran(st);
	printf("\n");
	system("pause");
	return 0;
}
