//第二次实验（写报告）
/*//最小公约数
#include<stdio.h>
int main()
{
int m,n,gcd,lcm,t,c;
scanf("%d %d",&m,&n);
c=m*n;
if(m>n)
    {
    	t=m;m=n;n=t;
    }
  t=m;
		while(t>0){
		m=t;
        t=n%m;
        n=m;
            }

gcd=m;lcm=c/gcd;
printf("最大公约数为：%d\n最小公倍数为：%d\n",gcd,lcm);
}
*/
/*//求奇数和
#include<stdio.h>
int main(){
    int data,sum=0;
    scanf("%d",&data);
    while(data>0){
        if(data%2==1){
            sum += data;
        }
        scanf("%d",&data);
    }
    printf("奇数和为%d",sum);
}

*/
/*//求最小整数
#include<stdio.h>
int main(){
int n,i,a,min,b;
scanf("%d",&n);
scanf("%d",&a);
min=a;
for (i=1;i<=n-1;i++)
    {
    scanf("%d",&b);
    if(b<min) min=b;

    }
    printf("最小的整数是：%d",min);
}

*/
/*//求各位数和

#include<math.h>
#include<stdio.h>
int main()
{
    int i,a,t,a2,n,sum,a1;
    sum=0,n=0;
    scanf("%d",&a);
    a1=a;a2=a;
    while (a>0)
    {
        n++;
        a /= 10;
    }
    for(i=1;i<=n;i++)
    {
        t=a1/pow(10,double(n-i));
        sum += t;
        printf("sum=%d\n",sum);
        a1=a1-t*pow(10,double(n-i));
    }
    sum += a1;
    printf("%d的位数为:%d\n各位数和为:%d\n",a2,n,sum);
}
*/
/*//费布拉切数列
#include <stdio.h>
main()
{
long f1,f2;
int i,n,day=2;
f1=f2=1;
scanf("%d",&n);
if(n==1||n==2)
{
    printf("需要1天能增长到%d",n);
}
else{
while(f2<n&&n>1)

{
   // printf("%12ld %12ld",f1,f2);

        f1=f1+f2;day++;
        if(f1>=n) {
                break;
        }
        else{
        f2=f1+f2;
        day++;
        }
}
printf("需要%d天能增长到%d",day,n);
}


}
*/
//第四次作业
/*//求数列和
#include<stdio.h>
#include<math.h>
double fact(int a);
int main()
{
    double t,x,s=1,i=1;
    scanf("%lf",&x);
    t=fabs(pow(x,i)/i);
    while (t>=0.00001){
        t=fabs(pow(x,i)/fact(i));
        s += t;
        i++;
    }
    printf("s=%.4lf",s);

    }
double fact(int a)
{
   int i;
   double s=1;
   for (i=1;i<=a;i++){
    s *= i;
   }
   return s;
}

*/
//水仙花数
/*//打印图像

#include<stdio.h>
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n/2;i++){
        for(j=i;j<=n/2;j++){
        printf("  ");
        }

        for(k=1;k<=2*i-1;k++){
            printf("* ");
        }
        printf("\n");
    }
    for(i=1;i<=n/2+1;i++){
        for(j=n/2;j>=n/2+2-i;j--){
        printf("  ");
        }

        for(k=1;k<=n+2-2*i;k++){
            printf("* ");
        }
        printf("\n");
    }



}


*/
/*//水仙花数
#include <stdio.h>
#include <math.h>
int main(){
int i,j=0,k,n,s=0,a[10];
scanf("%d",&n);
for(i=(int)pow(10.0,n-1);i<(int)pow(10.0,n);i++)
{
k=i;
while(k)
{
a[j]=k%10;
s+=(int)pow(double(a[j]),n);
k/=10;
j++;
}
if(s==i) printf("%d ",i);
j=0;s=0;
}
return 0;
}

*/
/*//水仙花数
#include<stdio.h>
int power(int x,int y)
{
    int i=1, a=1;
    while(i<=y)
    {
        a = a * x;
        i++;
    }
    return a;
}

int main()
{
    int i,h,n,s,m=0,b;
    scanf("%d",&n);
    for(s=power(10,n-1);s<power(10,n);s++)
    {
        b=s;
        m = 0;
        for(i=1;i<=n;i++)
        {
            h=b%10;
            m=m+power(h,n);
            b=b/10;
        }
        if(m==s) printf("%d\n",m);
    }

    return 0;
}
*/
/*//水仙花数（完整版）
#include<stdio.h>
#include<math.h>
int power(int x,int y)
{
    int i=1, a=1;
    while(i<=y)
    {
        a = a * x;
        i++;
    }
    return a;
}
int main()
{
    int t,i,j,n,data,data1,sum;
    scanf("%d",&n);
    for(i=power(10,n-1);i<power(10.0,n)-1;i++)
    {
        data=i;data1=i;sum=0;t=1;
        while (data/10!=0){
            t++;
            data /= 10;
        }

        //位数为t

        for(j=1;j<=t-1;j++){
            sum += power(data1/power(10.0,t-j),n);
            data1 = fmod(data1,power(10.0,t-j));
        }
        sum += power(data1,n);
ssss
        if(sum==i) printf ("%ld\n",i);
    }

    */
/*//十进制转换为八进制


#include<stdio.h>
#include<malloc.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct {
    int *base;
    int *top;
    int stacksize;
}Sqstack;

void Initstack(Sqstack &s)
{
    s.base=(int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if(!s.base)
        return;
    s.top=s.base;
    s.stacksize=STACK_INIT_SIZE;
}

int Push(Sqstack &s,int e)
{
    if(s.top-s.base>s.stacksize)
    {
        s.base=(int *)realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(int));
        if(!s.base)
            return false;
        s.top=s.base+s.stacksize;
        s.stacksize+=STACKINCREMENT;
    }
    *s.top++=e;
    return true;
}

int Pop(Sqstack &s,int &e)
{
    if(s.top==s.base)
        return false;
    e=*--s.top;
    return true;
}

int main()
{
    int N,e;
    Sqstack s;
    Initstack(s);
    scanf("%d",&N);
    while(N)
    {
        Push(s,N%8);
        N/=8;
    }
    while(s.base!=s.top)
    {
        Pop(s,e);
        printf("%d",e);
    }
    return 0;
}
*/
/*//书本题目117
#include<stdio.h>
int fun3(int m);
int main()
{
    int n;
    for(n=1;n<10;n++){
        if(fun3(n)==1 ) printf("%d",n);
    }
        return 0;
    }

int fun3(int m)
{
    int i;
    if(m==2||m==3) return 1;
    if(m<2||m%2==0) return 0;
    for(i=3;i<m;i=i+2)
        if(m%i==0) return 0;
    return 1;
}
*/
/*//链表
void transmatrix(tripletable a, tripletable &b){
   b.m=a.n;  b.n=a.m;   b.t=a.t;
   if(b.t>0){
     q=0;
     for(col=1; col<=a.n; col++)
        for(p=0; p<a.t; p++)
          if (a.data[p].j==col )  {
             b.data[q].i=a.data[p].j;
             b.data[q].j=a.data[p].i;
             b.data[q].v=a.data[p].v;
             q++;
         }
    }
}
*/
/*实验题1-2  约瑟夫环问题
【问题描述】编号为1，2，···，n的n个人围坐在一圆桌旁。从第一个人开始报数，
报到一个预先约定的正整数m时，停止报数，报m的人退席，下一个人又重新从1开始报数，
依此重复，直至所有的人都退席。编一程序输出他们退席的编号序列。
【要求】采用顺序结构或链式结构完成以上程序。
【提示】用不带表头结点的循环单链表表示围成圆圈的n个人；建立此循环单链表；
某人离席相当于删除一个结点要正确设置程序中循环终止的条件和删除结点时指针的修改变化。
【测试数据】 m=20，n=7，退席的人的编号依次为6，1，7，5，3，2，4
*/
/*
#include<stdio.h>
void josephus();
int main()
{
    typedef struct node{
        int data;
        struct node *next;

    }node,*LinkList;
    int m,n;
    LinkList(r);
    scanf("%d %d",&m,&n);

    int i,j;
    LinkList p=r,q;
    for(i=1;i<=n;++i){
        for(j=1;j<=m-1;++j)p=p->next;
        q=p->next;
        printf("%d",q->data);
        p->next=q->next;
    }
}

*/
/*
    #include <stdio.h>
    #include <stdlib.h>
    typedef struct node{
    int data;
    struct node * next;
    }node,*LinkList;

    LinkList * initLink(int n){
    LinkList * head=(LinkList*)malloc(sizeof(LinkList));
    head->data=1;
    head->next=NULL;
    LinkList * cyclic=head;
    for (int i=2; i<=n; i++) {
    LinkList * body=(LinkList*)malloc(sizeof(LinkList));
    body->data=i;
    body->next=NULL;
    cyclic->next=body;
    cyclic=cyclic->next;
    }
    cyclic->next=head;//首尾相连
    return head;
    }
    void findAndKillK(LinkList * head,int k,int m){
    LinkList * tail=head;
    //找到链表第一个结点的上一个结点，为删除操作做准备
    while (tail->next!=head) {
    tail=tail->next;
    }
    LinkList * p=head;
    //找到编号为k的人
    while (p->data!=k) {
    tail=p;
    p=p->next;
    }
    //从编号为k的人开始，只有符合p->next==p时，说明链表中除了p结点，所有编号都出列了，
    while (p->next!=p) {
    //找到从p报数1开始，报m的人，并且还要知道数m-1de人的位置tail，方便做删除操作。
    for (int i=1; i<m; i++) {
    tail=p;
    p=p->next;
    }
    tail->next=p->next;//从链表上将p结点摘下来
    printf("出列人的编号为:%d\n",p->data);
    free(p);
    p=tail->next;//继续使用p指针指向出列编号的下一个编号，游戏继续
    }
    printf("出列人的编号为:%d\n",p->data);
    free(p);
    }
    int main() {
    printf("输入圆桌上的人数n:");
    int n;
    scanf("%d",&n);
    LinkList * head=initLink(n);
    printf("从第k人开始报数(k>1且k<%d)：",n);
    int k;
    scanf("%d",&k);
    printf("数到m的人出列：");
    int m;
    scanf("%d",&m);
    findAndKillK(head, k, m);
    return 0;
    }
*/
/*
#include<stdio.h>

#include<stdlib.h>

#define maxsize 100

typedef chardatatype;

typedef structnode1//顺序表结点定义

{

    datatype data[maxsize];

    int length;

}Seqlist,*Pseqlist;





typedef structnode2//循环链表结点定义

{

    datatype data;

    structnode2 *next;

}Lnode,*Linklist;



//1. 以下为顺序表操作

Pseqlist Creat1(intn)

//创建顺序表，已知到顺序表个数n

{

    Pseqlist L;

    int i=0;

    L = (Pseqlist)malloc(sizeof(Seqlist));

    L->length = 0;

    printf("请输入顺序表中的元素：\n");

    while(i<=n)

    {

         scanf_s("%c", &(L->data[i]),1);

         L->length++;

         i++;

    }



    return (L);

}



void Deleteseqlist(PseqlistL,inti)

//删除顺序表中的元素

{

    int j;

    if (!L)

    {

         printf("表不存在");

    }

    if (i<1 || i>L->length)

    {

         printf("删除位置不合法\n");

    }



    for (j =i;j <L->length;j++)

         L->data[j - 1] =L->data[j];

    L->length--;



}







void jSeqlist(PseqlistL,ints,intm)

//顺序表的约瑟夫环解法

{

    int s1, i;



    datatype w;

    if (!L->length)

    {

         printf("表中无元素！");

    }

    s1 = s - 1;

    printf("输出相应的jseqlist序列：\n");



    for (i =L->length;i > 0;i--)

    {

         s1 = (s1 +m - 1) % i;



         w = L->data[s1];

         printf("%4c", w);

         Deleteseqlist(L,s1+1);

    }

}
*/
/*

#include<stdio.h>

#include<stdlib.h>

//声明循环链表结构体

typedef struct LNode

{

      int num;//数据域

      struct LNode *next;//结构体指针

}LNode;//结点类型



//创建结点

LNode *Create_node(int Lnum)

{

      LNode *Lp;//创建结点指针

      Lp=(LNode *)malloc(sizeof(LNode));//分配动态储存空间

      Lp->num=Lnum;//*Lp指向num，把num的值传给Lnum

      Lp->next=NULL;//*Lp指向下一个元素结点为空，确定*Lp是头结点指针

      return Lp;//返回头结点指针

}



//创建循环链表

LNode *Create_Linklist(LNode *pHead, int Lsum)

{

      int k;

      LNode *p, *temp;//创建两个指针

      for(k=1;k<=Lsum;k++)//遍历整个链表

      {

             p=Create_node(k);

             //如果链表为空，创建链表第一个结点，其next指针指向自身

             if(pHead==NULL)

             {

                    temp=p; //把p的值传给temp

                    pHead=p; //把p的值传给pHead

                    temp->next=pHead; //让*temp指向的下一个位置为pHead

             }

             //否则，执行插入节点操作

             else

             {

                    p->next=temp->next;//空白指针跟着*p后面，一个接一个插入

                    temp->next=p;

                    temp=p; //把p的值再传给temp

             }

      }

//测试是否生成循环链表成功！



      p=pHead;

      k=1;//初始化k的值

      while(p->next!=pHead)//用循环输出链表中的元素

      {

             printf("第%d个小孩的编号为：%d\n",k,p->num);

             p=p->next;//指针移向下一个位置

             k++;

      }

      printf("第%d个小孩的编号为：%d\n\n",k,p->num);//确保最后一个元素能显示出来



      return pHead;//返回头指针

}



//执行出列操作

void Delete_Linklist(LNode *pHead,int Lstart, int Ldel)

{

      int i,count=1;//count为计数器

      LNode *p, *temp;

      p=pHead;

      //找到第M个孩子所在的位置

      for(i=1;i<Lstart;i++)

             p=p->next;

      //只剩1个结点时终止循环

      while(p->next!=p)

      {

             //找到要出列的孩子的位置

             for(i=1;i<Ldel;i++)

             {

                    temp=p;

                    p=p->next;

             }

             //执行出列操作

             temp->next=p->next;//让*temp指向*p后面的结点

             printf("第%d个出列的小孩的编号为：%d\n",count,p->num);

             free(p);//释放*p

             count++;

             //出列者的下一个孩子作为新的第一个报数者

             p=temp->next;

      }

      printf("第%d个出列的小孩的编号为：%d\n",count,p->num);

      free(p);

      //所有人均出列，头结点释放后赋空值，避免出现悬垂指针

      pHead=NULL;

}



int main()

{

      int n,b,k;

      LNode *pHead=NULL, *p;//执行初始化操作

    //输入字符的合法性验证暂时忽略

      printf("请输入小孩的个数：\n");

      scanf("%d",&n);

      printf("请输入开始报数的小孩编号：\n");

      scanf("%d",&b);

      printf("请输入报数数目：\n");

      scanf("%d",&k);

      p=Create_Linklist(pHead,n);//调用创建链表函数

      Delete_Linklist(p,b,k);//调用删除链表函数

      return 0;

}
*/
//第五次作业
/*//sign(x)
#include<stdio.h>
int signa(int n);
int main()
{
    int x,y;
    scanf("%d",&x);
    y=signa(x);
    printf("%d",y);
}
int signa(int n)
{
    int m;
    if(n >0)  m= 1;
    if(n <0)  m= -1;
    if(n==0)  m= 0;
    return m;

}
*/
/*//图像打印
#include<stdio.h>
void pyramid(int n);
int main()
{
    int n;
    scanf("%d",&n);
    pyramid(n);
    return 0;
}

void pyramid(int n)
{
    int i ,j;
    for(i=1;i<=n;i++){
        for (j=1;j<=n-i;j++)
            printf(" ");
        for(j=1;j<=i;j++)
            printf("%d ",i);
    putchar('\n');
    }
}

*/
/*//奇数和
#include<stdio.h>
int even(int n);
int main()
{
    int x,sum=0;
    scanf("%d",&x);
    while(x!=0){
        if(even(x)==0) sum +=x;
        scanf("%d",&x);
    }
    printf("奇数和为:%d",sum);
}
int even(int x)
{
    if(x%2==1){
        return 0;
    }else{return 1;}
}

*/

/*//素数和
#include<stdio.h>
int prime(int n);
int main()
{
    int m,n,t,i,sum=0,cnt=0;
    scanf("%d %d",&m,&n);
    if(m>n) {
        t=m;m=n;n=t;
    }
    printf("素数有:\n");
    for(i=m+1;i<=n;i++){
        if(prime(i)) {
                sum += i;
                cnt++;
                printf("%d\n",i);
        }
    }
    printf("素数有%d个，它们的和为:%d\n",cnt,sum);
}
int prime(int n)
{
    int i,j=1;
    if(n==1){
        return 0;
    }
    else if(n==2){
        return 1;
    }else{
    for(i=2;i<n;i++)
    {
        if(n%i==0) j=0;
    }
    return j;
    }
}
*/

/*
//水仙花数
#include<stdio.h>
int Narcissistic(int n);
int pow(int a,int b);
int main()
{

    int i,m,t,n;
    scanf("%d %d",&m,&n);
    printf("水仙花数有：\n");
    if(m>n){
        t=m;m=n;n=t;
    }
    for(i=m;i<=n;i++){
        if(Narcissistic(i)&&(i!=1)) printf("%d\n",i);
    }
}
int Narcissistic(int n)
{
    int b=n,m=n,t=1,sum=0;
    while(b/10!=0){
        t++;b/=10;
    }
    while(m/10!=0){
        sum += pow(m%10,3);
        m/=10;
    }
    sum+=pow(m,3);
    if(sum==n) {
        return 1;
    }else{return 0;}

}
int pow(int a,int b)
{
    int i,t=1;
    for(i=1;i<=b;i++) t*=a;
    return t;
}

*/

//第三次实验
/*//绝对值函数
#include<stdio.h>
int abs1(int n);
int main()
{
    int x;
    scanf("%d",&x);
    printf("x的绝对值为：%d",abs1(x));
}

int abs1(int n)
{
    int a;
    if(n<0) {
        a=-n;
    }else{a=n;}
    return a;
}
*/
//递归法求x的y次幂
/*
#include<stdio.h>
int xy(int x,int y);
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    printf("%d的%d次幂为:%d\n",m,n,xy(m,n));

  }
int xy(int x,int y)
{
    int a;
if(y==0){
    a=1;
}
else if(y==1){
    a=x;
}else{
    a=xy(x,y-1)*x;
}
return a;
}

*/
/*//求奇数和
#include<stdio.h>
int even(int n);
int main()
{
    int x,sum=0;
    scanf("%d",&x);
    while(x!=0){
        if(even(x)==0) sum +=x;
        scanf("%d",&x);
    }
    printf("奇数和为:%d",sum);
}
int even(int x)
{
    if(x%2==1){
        return 0;
    }else{return 1;}
}

*/
/*
#include<stdio.h>
#include<math.h>
double fact(int n);
double funcos(double e,int x);
int main(void)
{
double x, e;
scanf("%lf %lf",&e,&x);
printf("cos(x)=%.3f\n",funcos(e,x));
}
double funcos(double e,int x)
{
int flag,i;
double sum,t;
t=flag=1;
i=sum=0;
while(fabs(t)>=e){
t=(flag*pow(x,i))/fact(i);
sum += t;
flag=-flag;
i += 2;
}
return sum;
}
double fact(int n)
{
int i;
double result=1;
for(i=1;i<=n;i++)result=result*i;
return result;
}
*/







