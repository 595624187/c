# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# define MAX_OPERATOR_NUM 100		//运算符栈数组长度
# define MAX_DATA_NUM 100		//运算数栈数组长度
typedef struct OPStack		//定义运算符栈
{
	char opStack[MAX_OPERATOR_NUM];
	int top;
}OPStack, *pOPStack;
typedef struct DATAStack		//定义操作数栈
{
	double stack[MAX_DATA_NUM];
	int top;
}DATAStack, *pDATAStack;
void InitpOPStack(pOPStack &pOStack)		//初始化运算符栈
{
	if( !(pOStack = (pOPStack)malloc(sizeof(OPStack))))			//为运算符栈分配空间
	{
		printf("分配内存空间失败!\n");
		exit(-1);
	}
	pOStack->top = -1;
}
void InitpDATAStack(pDATAStack &pDStack)		//初始化运算数栈
{
	if( !(pDStack = (pDATAStack)malloc(sizeof(DATAStack))))			//为运算数栈分配空间
	{
		printf("分配内存空间失败!\n");
		exit(-1);
	}
	pDStack->top = -1;
}
void PushOPStack(pOPStack &pOStack, char ch)		//运算符进栈
{
	pOStack->opStack[++(pOStack->top)] = ch;
}
void PopOPStack(pOPStack &pOStack, char &ch)		//运算符出栈
{
	ch = pOStack->opStack[pOStack->top];
	pOStack->top--;
}
void PushDATAStack(pDATAStack &pDStack, double d)		//运算数进栈
{
	++(pDStack->top);
	pDStack->stack[pDStack->top] = d;
}
void PopDATAStack(pDATAStack &pDStack, double &d)		//运算数出栈
{
	d = pDStack->stack[pDStack->top];
	pDStack->top--;
}
void ClearpOPStack(pOPStack &pOStack)		//清空运算符栈
{
	pOStack->top = -1;
}
void ClearpDATAStack(pDATAStack &pDStack)			//清空运算数栈
{
	pDStack->top = -1;
}
char GetToppOPStack(pOPStack &pOStack)			//获取运算符栈顶元素
{
	return pOStack->opStack[pOStack->top];
}
double GetToppDATAStack(pDATAStack &pDStack)			//获取运算数栈顶元素
{
	return pDStack->stack[pDStack->top];
}
bool IsOP(char &ch)			//区分 运算符 和 运算数 的函数，是运算符时返回true,否则返回false
{	//判断是否为符号
	if ( (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (ch == '=') || (ch == 'A') || (ch == 'S') || (ch == 'a') || (ch == 's') || (ch == '(') || (ch == ')') )
		return true;
	else
		return false;
}
char Precede(char op1, char op2) //参考《数据结构》（C语言版）第53页 3.2.5表达式求值 表 3.1
{
	char tab[9][10];		//定义字符串的二维数组来存放运算符优先级的关系
	strcpy( tab[0], ">><<<><<>" );
	strcpy( tab[1], ">><<<><<>" );
	strcpy( tab[2], ">>>><><<>" );
	strcpy( tab[3], ">>>><><<>" );
	strcpy( tab[4], "<<<<<=<<E" );
	strcpy( tab[5], ">>>>E>>>>" );
	strcpy( tab[6], ">>>><>>>>" );
	strcpy( tab[7], ">>>><>>>>" );
	strcpy( tab[8], "<<<<<E<<=" );
	char op[10];		//定义一维字符串数组来按优先级从低到高存放运算符
	strcpy(op, "+-*/()AS=");
	int i, j;

	for( i = 0; i < 9; i++)
		if( op[i] == op1)
			break;
	for( j = 0; j < 9; j++)
		if( op[j] == op2)
			break;
	return tab[i][j];		//返回比较结果
}
void exit_E()
{
		printf("\n	|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
		printf("\n	|	***欢迎您的下次使用!谢谢!!!***			|	\n\n");		//退出使用
		printf("	|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n\n");
}
double Operate(double a, char theta, double b)		//对出栈的运算符和运算数进行计算
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
		if ( b != 0 )		//判断除数是否为0，若为0，退出程序
		{
			s = a/b;
			break;
		}
		else
		{
			printf("\n		#### 除数为0，非法运算。程序终止! ####\n");
			exit_E();		//打印结束菜单
			exit(-1);
		}
	case 'A':
		s = fabs(b);		//调用FABS()函数
		break;
	case 'S':
		if( b >= 0)			//判断被开方数是否为0，若为0，退出程序
		{
			s = sqrt(b);		//调用SQRT()函数
			break;
		}
		else
		{
			printf("\n		#### 求负数的平方根是非法运算。程序终止! ####\n");
			exit_E();		//打印结束菜单
			exit(-1);
		}
	}
	return s;
}
char ChangeChar(char &c)		//通过ChangeChar函数来把a、s的小写字母改为大写的
{
	if( c == 'a' )
		c = 'A';
	else if( c == 's' )
		c = 'S';
	return c;
}
//参考《数据结构》（C语言版）第53页 3.2.5表达式求值 算法3.4	EvaluateExpression()函数
void EvaluateExpression()		//计算函数：读入表达式，并计算结果
{
	pOPStack pOStack;		//声明运算符栈
	pDATAStack pDStack;			//声明运算数栈
	double result;		//存运算的结果
	char x, theta, c;		//c存放读取的字符,x、theta存放运算符栈的栈顶元素
	int flag, data;			//标识符，用来读入连续的数字
	double s;
	double getd;		//存放GetTop***的结果
	double a, b, cc;		//a,b存放数据栈出栈的栈顶元素, c存放运算结果
	flag = 0;		//初始化标识符，用来判断字符串中的连续数字
	data = 0;		//
	InitpOPStack(pOStack);		//初始化运算符栈
	InitpDATAStack(pDStack);		//初始化运算数栈
	PushOPStack(pOStack, '=');		//在运算符栈底放入'='
	printf("	&请输入表达式以'='结束：");
	c = getchar();		//读入字符
	ChangeChar(c);		//通过调用函数来实现把小写的a、s改为大写的A、S

	while( c != '=' || GetToppOPStack(pOStack) != '=')
	{
		if( !IsOP(c) )			//不是运算符进栈
		{
			s = c - '0';		//把字符转化为数字
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
			switch( Precede(GetToppOPStack(pOStack), c) )		//输入元素和运算符栈顶元素比较
			{
			case '<':		//栈顶元素优先级低
				PushOPStack(pOStack, c);
				c = getchar();
				ChangeChar(c);
				break;
			case '=':		//托括号并接受下一个字符
				PopOPStack(pOStack, x);
				c = getchar();
				ChangeChar(c);
				break;
			case '>':		//退栈并将运算结果进栈
				PopOPStack(pOStack, theta);
				PopDATAStack(pDStack, b);
				PopDATAStack(pDStack, a);

				cc = Operate(a, theta, b);
				PushDATAStack(pDStack, cc);
				break;
			}//switch
		}//else
	}//while
	result = GetToppDATAStack(pDStack);		//运算结束时，运算数栈的栈底元素就是计算结果
	ClearpOPStack(pOStack);			//清空运算符栈
	ClearpDATAStack(pDStack);		//清空运算数栈
	printf("	->计算结果为：%.2f\n\n", result);		//输出运算结果
	return ;
}
void print_user()		//欢迎界面
{
	printf("\n			欢迎使用C语言版模拟计算器		\n\n");
	printf("************************************************************************\n");
	printf("	|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("	|		模拟计算器使用说明			|\n\n");
	printf("	|				   作者：谢先斌		|\n\n");
	printf("	|	本程序包括对'+'、'-'、'*'、'/'、'()'的运算	|\n");
	printf("	|	本程序中ABS()算用A()替代、SQRT()运算用S()代替	|\n");
	printf("	|	本程序中的一切字母均不区分大小写		|\n");
	printf("		正确的表达式如：1+A(7-8)+S(9*8)=		\n");
	printf("	|	输入'='表示表达式输入结束!!			|\n\n");
	printf("	|				 欢迎使用!!!-->-->      |\n");
	printf("	|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");
	printf("************************************************************************\n\n");
}
int main()		//主函数
{
	char in;
	bool b;		//标识符，用来标识是否结束程序
	b = true;		//初始化，不结束
	print_user();		//打印欢迎界面
	printf("	*请确认使用计算器Y/N:");
	while(1)
	{
		scanf("%c", &in);		//确认是否继续操作
		getchar();		//吃掉会车，避免干扰
		switch(in)
		{
		case 'Y':
		case 'y':
			{
				EvaluateExpression();		//进入计算函数：读入表达式，并计算结果
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
		//	printf("	**输入错误，请重新输入Y/N:");
		//	break;
		}
		if(b==false)		//如果 b==false ,退出整个程序
			break;
		printf("	*您确定要继续使用计算机Y/N:");
		getchar();		//用getchar吃掉回车，避免对后续输入中in的干扰
	}
	return 0;
}
