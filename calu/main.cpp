# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# define MAX_OPERATOR_NUM 100		//�����ջ���鳤��
# define MAX_DATA_NUM 100		//������ջ���鳤��
typedef struct OPStack		//���������ջ
{
	char opStack[MAX_OPERATOR_NUM];
	int top;
}OPStack, *pOPStack;
typedef struct DATAStack		//���������ջ
{
	double stack[MAX_DATA_NUM];
	int top;
}DATAStack, *pDATAStack;
void InitpOPStack(pOPStack &pOStack)		//��ʼ�������ջ
{
	if( !(pOStack = (pOPStack)malloc(sizeof(OPStack))))			//Ϊ�����ջ����ռ�
	{
		printf("�����ڴ�ռ�ʧ��!\n");
		exit(-1);
	}
	pOStack->top = -1;
}
void InitpDATAStack(pDATAStack &pDStack)		//��ʼ��������ջ
{
	if( !(pDStack = (pDATAStack)malloc(sizeof(DATAStack))))			//Ϊ������ջ����ռ�
	{
		printf("�����ڴ�ռ�ʧ��!\n");
		exit(-1);
	}
	pDStack->top = -1;
}
void PushOPStack(pOPStack &pOStack, char ch)		//�������ջ
{
	pOStack->opStack[++(pOStack->top)] = ch;
}
void PopOPStack(pOPStack &pOStack, char &ch)		//�������ջ
{
	ch = pOStack->opStack[pOStack->top];
	pOStack->top--;
}
void PushDATAStack(pDATAStack &pDStack, double d)		//��������ջ
{
	++(pDStack->top);
	pDStack->stack[pDStack->top] = d;
}
void PopDATAStack(pDATAStack &pDStack, double &d)		//��������ջ
{
	d = pDStack->stack[pDStack->top];
	pDStack->top--;
}
void ClearpOPStack(pOPStack &pOStack)		//��������ջ
{
	pOStack->top = -1;
}
void ClearpDATAStack(pDATAStack &pDStack)			//���������ջ
{
	pDStack->top = -1;
}
char GetToppOPStack(pOPStack &pOStack)			//��ȡ�����ջ��Ԫ��
{
	return pOStack->opStack[pOStack->top];
}
double GetToppDATAStack(pDATAStack &pDStack)			//��ȡ������ջ��Ԫ��
{
	return pDStack->stack[pDStack->top];
}
bool IsOP(char &ch)			//���� ����� �� ������ �ĺ������������ʱ����true,���򷵻�false
{	//�ж��Ƿ�Ϊ����
	if ( (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '=') || (ch == 'A') || (ch == 'S') || (ch == 'a') || (ch == 's') || (ch == '(') || (ch == ')') )
		return true;
	else
		return false;
}
char Precede(char op1, char op2) //�ο������ݽṹ����C���԰棩��53ҳ 3.2.5���ʽ��ֵ �� 3.1
{
	char tab[9][10];		//�����ַ����Ķ�ά�����������������ȼ��Ĺ�ϵ
	strcpy( tab[0], ">><<<><<>" );
	strcpy( tab[1], ">><<<><<>" );
	strcpy( tab[2], ">>>><><<>" );
	strcpy( tab[3], ">>>><><<>" );
	strcpy( tab[4], "<<<<<=<<E" );
	strcpy( tab[5], ">>>>E>>>>" );
	strcpy( tab[6], ">>>><>>>>" );
	strcpy( tab[7], ">>>><>>>>" );
	strcpy( tab[8], "<<<<<E<<=" );
	char op[10];		//����һά�ַ��������������ȼ��ӵ͵��ߴ�������
	strcpy(op, "+-*/()AS=");
	int i, j;

	for( i = 0; i < 9; i++)
		if( op[i] == op1)
			break;
	for( j = 0; j < 9; j++)
		if( op[j] == op2)
			break;
	return tab[i][j];		//���رȽϽ��
}
void exit_E()
{
		printf("\n	|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf("\n	|	***��ӭ�����´�ʹ��!лл!!!***			|	\n\n");		//�˳�ʹ��
		printf("	|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n\n");
}
double Operate(double a, char theta, double b)		//�Գ�ջ������������������м���
{
	double s;
	switch(theta)
	{
	case '+':
		s = a + b;
		break;
	case '-':
		s = a - b;
		break;
	case '*':
		s = a * b;
		break;
	case '/':
		if ( b != 0 )		//�жϳ����Ƿ�Ϊ0����Ϊ0���˳�����
		{
			s = a/b;
			break;
		}
		else
		{
			printf("\n		#### ����Ϊ0���Ƿ����㡣������ֹ! ####\n");
			exit_E();		//��ӡ�����˵�
			exit(-1);
		}
	case 'A':
		s = fabs(b);		//����FABS()����
		break;
	case 'S':
		if( b >= 0)			//�жϱ��������Ƿ�Ϊ0����Ϊ0���˳�����
		{
			s = sqrt(b);		//����SQRT()����
			break;
		}
		else
		{
			printf("\n		#### ������ƽ�����ǷǷ����㡣������ֹ! ####\n");
			exit_E();		//��ӡ�����˵�
			exit(-1);
		}
	}
	return s;
}
char ChangeChar(char &c)		//ͨ��ChangeChar��������a��s��Сд��ĸ��Ϊ��д��
{
	if( c == 'a' )
		c = 'A';
	else if( c == 's' )
		c = 'S';
	return c;
}
//�ο������ݽṹ����C���԰棩��53ҳ 3.2.5���ʽ��ֵ �㷨3.4	EvaluateExpression()����
void EvaluateExpression()		//���㺯����������ʽ����������
{
	pOPStack pOStack;		//���������ջ
	pDATAStack pDStack;			//����������ջ
	double result;		//������Ľ��
	char x, theta, c;		//c��Ŷ�ȡ���ַ�,x��theta��������ջ��ջ��Ԫ��
	int flag, data;			//��ʶ����������������������
	double s;
	double getd;		//���GetTop***�Ľ��
	double a, b, cc;		//a,b�������ջ��ջ��ջ��Ԫ��, c���������
	flag = 0;		//��ʼ����ʶ���������ж��ַ����е���������
	data = 0;		//
	InitpOPStack(pOStack);		//��ʼ�������ջ
	InitpDATAStack(pDStack);		//��ʼ��������ջ
	PushOPStack(pOStack, '=');		//�������ջ�׷���'='
	printf("	&��������ʽ��'='������");
	c = getchar();		//�����ַ�
	ChangeChar(c);		//ͨ�����ú�����ʵ�ְ�Сд��a��s��Ϊ��д��A��S

	while( c != '=' || GetToppOPStack(pOStack) != '=')
	{
		if( !IsOP(c) )			//�����������ջ
		{
			s = c - '0';		//���ַ�ת��Ϊ����
			if ( flag == 1 )
			{
				PopDATAStack(pDStack, getd);
				s = getd*10 + s;
			}
			PushDATAStack(pDStack, s);
			flag = 1;
			c = getchar();
			ChangeChar(c);
		}
		else
		{
			flag = 0;
			switch( Precede(GetToppOPStack(pOStack), c) )		//����Ԫ�غ������ջ��Ԫ�رȽ�
			{
			case '<':		//ջ��Ԫ�����ȼ���
				PushOPStack(pOStack, c);
				c = getchar();
				ChangeChar(c);
				break;
			case '=':		//�����Ų�������һ���ַ�
				PopOPStack(pOStack, x);
				c = getchar();
				ChangeChar(c);
				break;
			case '>':		//��ջ������������ջ
				PopOPStack(pOStack, theta);
				PopDATAStack(pDStack, b);
				PopDATAStack(pDStack, a);

				cc = Operate(a, theta, b);
				PushDATAStack(pDStack, cc);
				break;
			}//switch
		}//else
	}//while
	result = GetToppDATAStack(pDStack);		//�������ʱ��������ջ��ջ��Ԫ�ؾ��Ǽ�����
	ClearpOPStack(pOStack);			//��������ջ
	ClearpDATAStack(pDStack);		//���������ջ
	printf("	->������Ϊ��%.2f\n\n", result);		//���������
	return ;
}
void print_user()		//��ӭ����
{
	printf("\n			��ӭʹ��C���԰�ģ�������		\n\n");
	printf("************************************************************************\n");
	printf("	|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("	|		ģ�������ʹ��˵��			|\n\n");
	printf("	|				   ���ߣ�л�ȱ�		|\n\n");
	printf("	|	�����������'+'��'-'��'*'��'/'��'()'������	|\n");
	printf("	|	��������ABS()����A()�����SQRT()������S()����	|\n");
	printf("	|	�������е�һ����ĸ�������ִ�Сд		|\n");
	printf("		��ȷ�ı��ʽ�磺1+A(7-8)+S(9*8)=		\n");
	printf("	|	����'='��ʾ���ʽ�������!!			|\n\n");
	printf("	|				 ��ӭʹ��!!!-->-->      |\n");
	printf("	|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("************************************************************************\n\n");
}
int main()		//������
{
	char in;
	bool b;		//��ʶ����������ʶ�Ƿ��������
	b = true;		//��ʼ����������
	print_user();		//��ӡ��ӭ����
	printf("	*��ȷ��ʹ�ü�����Y/N:");
	while(1)
	{
		scanf("%c", &in);		//ȷ���Ƿ��������
		getchar();		//�Ե��ᳵ���������
		switch(in)
		{
		case 'Y':
		case 'y':
			{
				EvaluateExpression();		//������㺯����������ʽ����������
				break;
			}
		case 'N':
		case 'n':
			{
				exit_E();
				b = false;
				break;
			}
		//default:
		//	printf("	**�����������������Y/N:");
		//	break;
		}
		if(b==false)		//��� b==false ,�˳���������
			break;
		printf("	*��ȷ��Ҫ����ʹ�ü����Y/N:");
		getchar();		//��getchar�Ե��س�������Ժ���������in�ĸ���
	}
	return 0;
}
