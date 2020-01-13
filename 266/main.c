/*#includ<stdio.h>
void MergeList (List La,List Lb,List &Lc){
InitList(Lc);
i=j=1;k=0;
La_len = ListLength(La);Lb_len = ListLength(Lb);
while((i<= La_len)&&(j<=Lb_len))
GetElem(La,i,ai); GetElem(Lb,j,bj);
if(ai<=bj){ListInsert(Lc,++k,ai);++i;}
else{ListInsert(Lc,++k,bj);++j;}
}
while(i<=La_len){
GetElem(La,i++,ai);ListInsert(Lc,++k,ai);
}
while(j<=Lb_len){
GetElem(Lb,j++,bj);ListInsert(Lc,++k,bj);
}
}
*/
/*
#include<stdio.h>
void main(void)
{

    long int f1,f2;int i;
    f1=1;f2=1;
    for(i=1;i<=20;i++){
        printf("%-12ld%-12ld",f1,f2);
        if(i%2==0)printf("\n");
        f1=f1+f2;f2=f2+f1;
    }
}
*/

/*#include<stdio.h>
void main(void)
{
    int x,y,z,n;printf("5 yuan 1 yuan 0.5 yuan\n");
    n=0;
    for(x=1;x<=100;x++)
        for(y=1;y<=100;y++)
        for(z=1;z<=100;z++)
        if(x+y+z==100&&5*x+y+0.5*z==100)
    {
        printf(" %-10d%-10d%-10d\n",x,y,z);n++;
    }
    printf("The combined changes %d kinds\n",n);
}

*/
/*#include "stdio.h"

int main()

{
   int a;
   scanf("%d",&a);
   int i,j,k,t;
   i=a;t=0;
   while (i<=a+3){
    j=a;
    while(j<=a+3)
    {
        k=a;
        while(k<=a+3){
           if(i!=j&&i!=k &&j!=k){
                        t++;
                     printf("%d%d%d",i,j,k);
                //printf("%d",i*100+j*10+k);
              if(t==6){
                printf("\n");
                t=0;
                }else{
                    printf(" ");
                }



           }


            k++;
        }
        j++;
    }
    i++;
   }

   return 0;
}

*/

/*#include "stdio.h"
int main(){
int a,b,n;
scanf("%d",&n);
for(a=1;a<=n;a++){
    for(b=1;b<=a;b++){
    printf("%d*%d=%d\t",b,a,a*b);
    }
printf("\n");
}
}
*/

/*

#include <stdio.h>
int main()
{
    int m,n,num=0,s=0,t,i,j,k;
    scanf("%d%d",&m,&n);
    for(i=m;i<=n;i++){
        t=1;
        for(k=2;k<i-1;k++)
        {
            if(i%k==0){
                t=0;

                break;
            }
        }
    if(t==1){
        num++;
        s+=i;
    }
}
    printf("%d  %d\n",num,s);


}

*/


/*
#include<stdio.h>
int main()
{
    int number,n;
    int inp;
    int finished = 0;
  int cnt = 0;
  scanf("%d %d",&number, &n);
    do{
            scanf("%d",&inp);
    cnt ++;
    if(inp < 0){
        printf("Game Over\n");
        finished = 1;

    }else if(inp>number){
    printf("Too big\n");
}else if(inp<number){
printf("Too small\n");
}else{
if(cnt==1){
    printf("Bingo!\n");
}else if(cnt<=3){
printf("Lucky YOu!\n");
}else{
printf("Good Guess!\n");
}
finished =1;
}
if(cnt==n){
    if(!finished){
        printf("Game Over!\n");
        finished =1;
    }
}
}while(!finished);
}
*/



/*
#include<stdio.h>
int main()
{
    int n,i;
    double a,b,c;
    a=2;b=1;c=0.0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
{
    c+=a/b;
    a=a+b;b=a;
}
printf("%.2f\n",c);
}

*/


/*

#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    int mask=1,t=x;
    if(x<0){
        printf("fu");
        x=-x;
    }
   while(t>9){
    t /= 10;
    mask *= 10;
   }
   do{
    int d=x/mask;
    switch(d){
    case 1:printf("一");break;
    case 2:printf("二");break;
    case 3:printf("三");break;
    case 4:printf("四");break;
    case 5:printf("五");break;
    case 6:printf("六");break;
    case 7:printf("七");break;
    case 8:printf("八");break;
    case 9:printf("九");break;
    case 0:printf("零");break;

    }
    //if(mask>9) printf(" ");
    x %= mask;
    mask /= 10;

   }while(mask>0);
   printf("\n");
   return 0;



}
*/
/*
#include<stdio.h>
int main()
{
    printf("sizeof(int)=%d\n",sizeof(int));
    printf("sizeof(float)=%d\n",sizeof(float));
    printf("sizeof(double)=%d\n",sizeof(double));
    printf("sizeof(long)=%d\n",sizeof(long));
    printf("sizeof(long long)=%d\n",sizeof(long long));
    printf("sizeof(long int)=%d\n",sizeof(long int));
    printf("sizeof(long double)=%d\n",sizeof(long double));

}
*/

/*
#include<stdio.h>
int main()
{
    char c =255;
    int  i =255;
    printf("c=%d,i=%d\n",c,i);
    // 11111111
    // 00000000 00000000 00000000 11111111
    return 0;
}


*/
/*

#include<stdio.h>
int main()
{
    int i,n=0;
    for(i=32;i<=127;i++){
    char c;
    c=i;
    n++;
    //scanf("%c",&c);
    printf("%.3d  %c | ",c,c);

if(n%5==0) printf("\n");
    }
}

*/





/*
#include<stdio.h>
#include<stdbool.h>
int main()
{
    bool b = 6<5;
    bool t = true;

    printf("%d\n%d", b,t);
    return 0;

}

*/
/*
#include<stdio.h>
void sum (int begin, int end)
{
    int i,sum=0;
    for(i=begin;i<=end;i++){
        sum+=i;
    }
    printf("%d到%d的和是%d\n",begin,end,sum);
}

int main()
{
    sum(1,10);
    sum(20,30);
    sum(35,45);
}

*/
/*
#include<stdio.h>
void cheer(int i)
{
    printf("cheer %d\n",i);
}
int main()
{
    double f = 2.0;
    cheer(f);

    return 0;
}

*/
/*
//  练习 2.4
#include<stdio.h>
int main()
{
    int c,f;
    f = 150;
   c=5*(f-32)/9;
    printf("%d",c);
}

*/

/*
//2.5
#include<stdio.h>
int main()
{
    double s,t,g;
    g=10.0;
    t=3.0;
    s=0.5*g*t*t;
    printf("%.2f",s);
}
*/
/*
#include<stdio.h>
#include<math.h>

int main()
{
    double y,x;
    scanf("%lf",&x);
    if(x<0)
    {
        y=pow(x,5)+2.0*x+1.0/x;
    }
    else
    {
        y=sqrt(x);
    }
    printf("%.2lf",y);
}


*/
/*
//物理实验报告公式计算
#include<stdio.h>
int main()
{
    double x,s;
    int i,n;
    s=0;
    scanf("%d",&n);

  for(i=1;i<=n;i++)
    {
        scanf("%lf",&x);
        s += x;
    }
    printf("和为=%.4lf\t平均数为=%.4lf\n",s,s/n);
}


*/

/*
#include<stdio.h>
int main()
{
    int i =0;
    int p;
    p=(int)&i;
    printf("00%x\n",p);
    printf("%p\n",&i);
    printf("%lu\n",sizeof(int));
    printf("%lu\n",sizeof(&i));
    return 0;
}

*/



/*



#include<stdio.h>
int main()
{
    int a[10];
    printf("%p\t%d\n",a,a);
    printf("%p\t%d\n",&a,&a);
    printf("%p\t%d\n",&a[1],&a[1]);
    printf("%p\t%d\n",&a[3],&a[3]);
}



*/










/*
#include<stdio.h>
int main()
{
    int a,b,c,t;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b)
    {
        t=a;
        a=b;
        b=t;
    }
    if(b>c);
    {
        t=b;
        b=c;
        c=t;
    }
     if(a>b)
    {
        t=a;
        a=b;
        b=t;
    }

    printf("%d\t%d\t%d",a,b,c);

}
*/


/*

#include<stdio.h>
int main()
{
    double v,v0,v1,v2;
    scanf("%lf",&v0);
    scanf("%lf",&v);
   v1=1.1*v0;v2=1.5*v0;
   // printf("%lf,%lf",v1,v2);
 if(v>=0&&v<v1){

        printf("正常行驶");

    }
     if(v<v2&&v>v1){
        printf("超速10%%，罚款200元");
    }

     if(v>=v2){
        printf("超速50%%，吊销驾驶证");
    }
    if(v<0)

    {
        printf("error!");
    }
}
*/
/*

#include<stdio.h>
int main()
{
    int i,n,x,y,z;

    scanf("%d",&n);
    for(i=1;i<=n;i++)
{
    scanf("%d",&x);
    if(x>=90) {
        printf("A\n");
    }
    else if(x>=80)
    {
        printf("B\n");
    }
    else if(x>=70){
        printf("C\n");

    }
    else if(x>=60){
        printf("E\n");
    }
}
}
*/

/*


#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;
typedef struct Node
{
    ElemType data;
    struct Node * next;
}Node,*LinkList;

//单链表的初始化
Status InitLinkList(LinkList * L)
{
    (*L)=(LinkList)malloc(sizeof(Node));
    if((*L)==NULL)
    {
        printf("内存分配失败！\n");
        return 0;
    }
    (*L)->next=NULL;
    return OK;
}

//单链表的建立
Status Create(LinkList * L,int n)
{
    LinkList P,Q;
    ElemType Elem;
    Q=(*L);
    printf("请按递增顺序输入元素：\n");
    for(int i=0;i<n;i++)
    {
        P=(LinkList)malloc(sizeof(Node));
        scanf("%d",&Elem);
        P->data=Elem;
        Q->next=P;
        Q=P;
    }
    P->next=NULL;
    return OK;
}


//删除结点
Status Delete(LinkList * L,int Location)
{
    LinkList Q,P;
    int count=0;
    int k=Location+1;
    Q=(*L);
    P=(*L)->next;
    while(P->next)
    {
        Q=Q->next;
        P=P->next;
        count++;
        if(count==Location)
        {
            Q->next=P->next;
        }
    }
    return OK;
}


//定位删除结点的位置并删除
Status Locate(LinkList * L)
{
    LinkList First,Second;
    int count=1;
    First=(*L)->next;
    Second=(*L)->next->next;
    while(Second)
    {
        if(First->data==Second->data)
        {
            Delete(L,count);
            Second=Second->next;
        }
        else
        {
            count++;
            First=First->next;
            Second=Second->next;
        }

    }
    return OK;
}


void Print(LinkList * L)
{
    LinkList P;
    P=(*L)->next;
    while(P)
    {
        printf("%d ",P->data);
        P=P->next;
    }
    printf("\n");
}



int main()
{
    LinkList L;
    int Number;
    InitLinkList(&L);
    printf("请输入元素个数：\n");
    scanf("%d",&Number);
    Create(&L,Number);
    printf("输出链表：\n");
    Print(&L);
    Locate(&L);
    printf("输出去掉相同元素后链表：\n");
    Print(&L);
    return 0;
}



*/
/*
#include<string.h>
#include<stdio.h>
int mylen(const char* s)
{

    int idx=1;
    while(s[idx]!='\0'){
        idx ++;


    }
    return idx;
}
int main()
{
    char line[]="Hello";
    printf("strlen=%lu\n",mylen(line));
    printf("sizeof=%lu\n",sizeof(line));
    //size_t strlen(const char* s);

}







*/
/*

    #include <stdio.h>
    #include <stdlib.h>
    char *mycat(char cat1[],const char cat2[]) //声明并实现我的猫字符指针函数。
    {
        int i = 0;
        int j = strlen(cat1);         //猫1字符数组的最后一位下标j
        while(i != strlen(cat2)){           //当猫2的下标为最后一位\0时跳出循环
            cat1[j] = cat2[i];         //猫1最后一位为猫二的第一位字符
            i++;
            j++;
        }
        cat1[j] = '\0';           //猫1字符数组最后一位为0
        return cat1;           //让我的猫字符指针指向猫1字符数组
    }
    int main(int argc, char const *argv[])
    {
        char str[] = "colroful\t";
        char str2[] = "night";
    //    scanf("%s",&str);
    //    scanf("%s",&str2);
        printf("%s",mycat(str,str2));           //输出我的猫函数值

    }
*/



/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (int argc, char const *argv[])
{
    char *s="hello";
    char *p = strchr(s,'l');
    char *t = (char*)malloc(strlen(p)+1);
    strcpy(t, p);
    printf("%s\n",t);
    free(t);
    return 0;

}


*/
/*
#include<stdio.h>
#include<stdlib.h>
#include"array.h"
Array array_create(int init_size)
{
    Array a;
    a.size = init_size;
    a.array = (int*)malloc(int)*a.size;
    return a;
}
void array_free(Array *a)
{

    free(a->array);
    a->array =NULL;
    a->size = 0;

}

int array_size(const Array*a)
{
    return a->size;

}
int* array_at(Array *a,int index)
{
    return &(a->array[index]);
}
void array_inflate(Array *a,int more_size)
{
    int *p=(int*)malloc(sizeof(int)(a->size + more_size));
    int i;
    for(i = 0;i<a->size;++){
        p[i]=a->array[i];

    }
    free(a->array);
    a->array = p;
    a - >size += more_size;

}
int main(int argc,char const *argv[])
{
    Array a = array_creat(100);
    Array_free(&a);
}



//链表慕课联系题目（未完成）



*/


/*
#include<stdio.h>
#include<string.h>
int main()
{
char a[20],c;
int n=0,b,i;
for(i=0;i<=17;i++){
    a[i]='X';
}
scanf("%18s",&a);
n=(a[0]-'0')*7+(a[1]-'0')*9+(a[2]-'0')*10+\
(a[3]-'0')*5+(a[4]-'0')*8+(a[5]-'0')*4+(a[6]-'0')*2+\
(a[7]-'0')*1+(a[8]-'0')*6+(a[9]-'0')*3+(a[10]-'0')*7+\
(a[11]-'0')*9+(a[12]-'0')*10+(a[13]-'0')*5+(a[14]-'0')*8+\
(a[15]-'0')*4+(a[16]-'0')*2;
b=n%11;
switch(b){
    case 0:c='1'; break;
    case 1:c='0'; break;
    case 2:c='X'; break;
    case 3:c='9'; break;
    case 4:c='8'; break;
    case 5:c='7'; break;
    case 6:c='6'; break;
    case 7:c='5'; break;
    case 8:c='4'; break;
    case 9:c='3'; break;
    case 10:c='2'; break;
}
if(c==a[17]){
    printf("这是一个合格的身份证号码");
}
else{
    printf("身份证号码错误！");
}
}




*/




/*
#include<stdio.h>
int main(){
    int num,sum=0;
    scanf("%d",&num);
    while(num>0){
        if(num%2==1){
            sum += num;
        }
        scanf("%d",&num);
    }
    printf("奇数和为%d",sum);
    }
*/


/*
#include<stdio.h>
int main()
{
    int n,i;
    double sum=0,a=2;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        a=a+i-1;
        sum += a/(1.0*i);


    }
    printf("序列和为：%.2lf",sum);
}

*/
/*
#include<stdio.h>
int main()
{
    int m,gcd,lcm,n,m1,n1,t;
    scanf("%d %d",&m,&n);
    m1=(m>n)?m:n;
    n1=(m>n)?n:m;
    //printf("m=%d\tn=%d\nm1=%d\tn1=%d",m,n,m1,n1);
    t=n1;
   while(t>0){
   n1=t;
   t=m1%n1;
   m1=n1;
   }
   gcd=n1;lcm=m*n/gcd;
   printf("最大公约数为：%d\n最小公倍数为：%d",gcd,lcm);
}

*/



/*


//mooc习题1样例

#include<stdio.h>
int main(){

Status Delete(LinkList * L,int Location)
{
LinkList Q,P;
int count=0;
int k=Location+1;
Q=(*L);
P=(*L)->next;
while(P->next)
{
Q=Q->next;
P=P->next;
count++;
if(count==Location)
{
Q->next=P->next;
}
}
return 1;
}

Status Locate(LinkList * L)
{
LinkList First,Second;
int count=1;
First=(*L)->next;
Second=(*L)->next->next;
while(Second)
{
if(First->data==Second->data)
{
Delete(L,count);
Second=Second->next;
}
else
{
count++;
First=First->next;
Second=Second->next;
}

}
return 1;
}




}

*/


#include<stdio.h>
#include<stdlib.h>
typedef struct _node
{
int value;
struct _node *next;
}Node;

typedef struct _list{
    Node* head;
}List;

void add(List* pList, int number);
int main(int argc, char const *argv[]){
    Node * head = NULL;
    List list;
    int number;
    do
    {
        scanf("%d",&number);
        if(number!=-1){
          head=add(&head,number);
         }
       } while(number!=1);
    return 0;
}

void add(List* pList, int number)
{
  Node *p=(Node*)malloc(sizeof(Node));
            p->value=number;
            p->next=NULL;
            Node *last =pList->head;
            if(last){
                while(last->next){
                    last=last->next;
                }
                last->next = p;
            }else{
                pList->head=p;
            }
            return pList->head;
}

/*
#include<stdio.h>
int main()
{
    FILE *fp = fopen("12.in","r");
    if(fp)
    {
        int num;
        fscanf("%d\n",num);
        fclose(fp);
    }else{
    printf("ERROR!\n");
    }
}

*/
/*
//线性表代码练习：
//有序插入
#define MAXSIZE 100
int main(){

typedef struct{
    ElemType a[MAXSIZE+1];
    int n;
}sqlist;
void sq_ins(sqlist &L,int i,ElemType x)
{
    int j;
    if(L.n==MAXSIZE) error("溢出;
        else if(i<1||i>L.n+1) error("位置错误");
        else{
            for(j=L.n;j>=i;j--)
                L.a[j+1]=L.a[j];
            L.a[i]=x;
            L.n++;
        }
}

*/
/*
//删除算法
#define MAXSIZE 100
typedef struct{
    ElemType a[MAXSIZE+1];
    int n;
    }sqlist;
    void sq_del(sqlist &L,int i,ElemType x){
        if(i<1||i>L.n) error("位置错误");
        else if {
            for (int j=i+1;j<=L.n;j++)
                L.a[j-1]=L.a[j];
            L.n--;
        }
    }
*/
//删除k位
/*
#define MAXSIZE 100
typedef struct{
    ElemType a[MAXSIZE+1];
    int n;
    }sqlist;
    void del(sqlist&L,int i,int k){
      if(k>0&&1<=i&&i+k<=L.n)
      {
          for(int j = i + k;j<= L.n;++j)
            L.a[j-k]=L.a[j];
      L.n-=k;
      }
        }
    }

*/



/*
    int judge(linklist L){                 
int b=1,x;
linklist p=L;                       //2分
do{
    x=p->next->data-p->data;
        if (x>2||x<-2)                  //1分
           b=0;                         //1分
        else
            p=p->next;                  //1分
    } while((p!=L)&& b)                  //2分
    return b;                           //1分
}

*/
/*
//1. 已知线性表中的元素以值递增有序排列，并以单链表作存储结构。试写一高效的算法，删除表中所有值相同的多余元素（使得操作后的线性表中所有元素的值均不相同），同时释放被删结点空间，并分析你的算法的时间复杂度。
void ListDelete_LSameNode(LinkList &L)
{·
     LinkList p,q,prev;
     p=L;
     prev=p;
     p=p->next;                     //    2分
     while(p){                     //    1分
         prev=p;
         p=p->next;                 //  2分
         if(p&&p->data==prev->data){        //  1分
              prev->next=p->next;
              q=p;
              p=p->next;           //  3分
              free(q);            //  1分
         }
     }
}

*/

/*


//2. 设一个环上有若干个整数，现采用单循环链表L存储该环，已知L的结点结构为：  data  next  ，试画出链表L的结构图，并编写算法判断环上任意两个相邻元素值之差的绝对值是否不超过2。

画出循环链表得2分，另外8分见算法
int judge(linklist L){                 
int b=1,x;
linklist p=L;                       //2分
do{
    x=p->next->data-p->data;
        if (x>2||x<-2)                  //1分
           b=0;                         //1分
        else
            p=p->next;                  //1分
    } while((p!=L)&& b)                  //2分
    return b;                           //1分
}
*/















