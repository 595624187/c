//�ڶ���ʵ�飨д���棩
/*//��С��Լ��
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
printf("���Լ��Ϊ��%d\n��С������Ϊ��%d\n",gcd,lcm);
}
*/
/*//��������
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
    printf("������Ϊ%d",sum);
}

*/
/*//����С����
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
    printf("��С�������ǣ�%d",min);
}

*/
/*//���λ����

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
    printf("%d��λ��Ϊ:%d\n��λ����Ϊ:%d\n",a2,n,sum);
}
*/
/*//�Ѳ���������
#include <stdio.h>
main()
{
long f1,f2;
int i,n,day=2;
f1=f2=1;
scanf("%d",&n);
if(n==1||n==2)
{
    printf("��Ҫ1����������%d",n);
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
printf("��Ҫ%d����������%d",day,n);
}


}
*/
//���Ĵ���ҵ
/*//�����к�
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
//ˮ�ɻ���
/*//��ӡͼ��

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
/*//ˮ�ɻ���
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
/*//ˮ�ɻ���
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
/*//ˮ�ɻ����������棩
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

        //λ��Ϊt

        for(j=1;j<=t-1;j++){
            sum += power(data1/power(10.0,t-j),n);
            data1 = fmod(data1,power(10.0,t-j));
        }
        sum += power(data1,n);
ssss
        if(sum==i) printf ("%ld\n",i);
    }

    */
/*//ʮ����ת��Ϊ�˽���


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
/*//�鱾��Ŀ117
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
/*//����
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
/*ʵ����1-2  Լɪ������
���������������Ϊ1��2����������n��n����Χ����һԲ���ԡ��ӵ�һ���˿�ʼ������
����һ��Ԥ��Լ����������mʱ��ֹͣ��������m������ϯ����һ���������´�1��ʼ������
�����ظ���ֱ�����е��˶���ϯ����һ�������������ϯ�ı�����С�
��Ҫ�󡿲���˳��ṹ����ʽ�ṹ������ϳ���
����ʾ���ò�����ͷ����ѭ���������ʾΧ��ԲȦ��n���ˣ�������ѭ��������
ĳ����ϯ�൱��ɾ��һ�����Ҫ��ȷ���ó�����ѭ����ֹ��������ɾ�����ʱָ����޸ı仯��
���������ݡ� m=20��n=7����ϯ���˵ı������Ϊ6��1��7��5��3��2��4
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
    cyclic->next=head;//��β����
    return head;
    }
    void findAndKillK(LinkList * head,int k,int m){
    LinkList * tail=head;
    //�ҵ������һ��������һ����㣬Ϊɾ��������׼��
    while (tail->next!=head) {
    tail=tail->next;
    }
    LinkList * p=head;
    //�ҵ����Ϊk����
    while (p->data!=k) {
    tail=p;
    p=p->next;
    }
    //�ӱ��Ϊk���˿�ʼ��ֻ�з���p->next==pʱ��˵�������г���p��㣬���б�Ŷ������ˣ�
    while (p->next!=p) {
    //�ҵ���p����1��ʼ����m���ˣ����һ�Ҫ֪����m-1de�˵�λ��tail��������ɾ��������
    for (int i=1; i<m; i++) {
    tail=p;
    p=p->next;
    }
    tail->next=p->next;//�������Ͻ�p���ժ����
    printf("�����˵ı��Ϊ:%d\n",p->data);
    free(p);
    p=tail->next;//����ʹ��pָ��ָ����б�ŵ���һ����ţ���Ϸ����
    }
    printf("�����˵ı��Ϊ:%d\n",p->data);
    free(p);
    }
    int main() {
    printf("����Բ���ϵ�����n:");
    int n;
    scanf("%d",&n);
    LinkList * head=initLink(n);
    printf("�ӵ�k�˿�ʼ����(k>1��k<%d)��",n);
    int k;
    scanf("%d",&k);
    printf("����m���˳��У�");
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

typedef structnode1//˳����㶨��

{

    datatype data[maxsize];

    int length;

}Seqlist,*Pseqlist;





typedef structnode2//ѭ�������㶨��

{

    datatype data;

    structnode2 *next;

}Lnode,*Linklist;



//1. ����Ϊ˳������

Pseqlist Creat1(intn)

//����˳�����֪��˳������n

{

    Pseqlist L;

    int i=0;

    L = (Pseqlist)malloc(sizeof(Seqlist));

    L->length = 0;

    printf("������˳����е�Ԫ�أ�\n");

    while(i<=n)

    {

         scanf_s("%c", &(L->data[i]),1);

         L->length++;

         i++;

    }



    return (L);

}



void Deleteseqlist(PseqlistL,inti)

//ɾ��˳����е�Ԫ��

{

    int j;

    if (!L)

    {

         printf("������");

    }

    if (i<1 || i>L->length)

    {

         printf("ɾ��λ�ò��Ϸ�\n");

    }



    for (j =i;j <L->length;j++)

         L->data[j - 1] =L->data[j];

    L->length--;



}







void jSeqlist(PseqlistL,ints,intm)

//˳����Լɪ�򻷽ⷨ

{

    int s1, i;



    datatype w;

    if (!L->length)

    {

         printf("������Ԫ�أ�");

    }

    s1 = s - 1;

    printf("�����Ӧ��jseqlist���У�\n");



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

//����ѭ������ṹ��

typedef struct LNode

{

      int num;//������

      struct LNode *next;//�ṹ��ָ��

}LNode;//�������



//�������

LNode *Create_node(int Lnum)

{

      LNode *Lp;//�������ָ��

      Lp=(LNode *)malloc(sizeof(LNode));//���䶯̬����ռ�

      Lp->num=Lnum;//*Lpָ��num����num��ֵ����Lnum

      Lp->next=NULL;//*Lpָ����һ��Ԫ�ؽ��Ϊ�գ�ȷ��*Lp��ͷ���ָ��

      return Lp;//����ͷ���ָ��

}



//����ѭ������

LNode *Create_Linklist(LNode *pHead, int Lsum)

{

      int k;

      LNode *p, *temp;//��������ָ��

      for(k=1;k<=Lsum;k++)//������������

      {

             p=Create_node(k);

             //�������Ϊ�գ����������һ����㣬��nextָ��ָ������

             if(pHead==NULL)

             {

                    temp=p; //��p��ֵ����temp

                    pHead=p; //��p��ֵ����pHead

                    temp->next=pHead; //��*tempָ�����һ��λ��ΪpHead

             }

             //����ִ�в���ڵ����

             else

             {

                    p->next=temp->next;//�հ�ָ�����*p���棬һ����һ������

                    temp->next=p;

                    temp=p; //��p��ֵ�ٴ���temp

             }

      }

//�����Ƿ�����ѭ������ɹ���



      p=pHead;

      k=1;//��ʼ��k��ֵ

      while(p->next!=pHead)//��ѭ����������е�Ԫ��

      {

             printf("��%d��С���ı��Ϊ��%d\n",k,p->num);

             p=p->next;//ָ��������һ��λ��

             k++;

      }

      printf("��%d��С���ı��Ϊ��%d\n\n",k,p->num);//ȷ�����һ��Ԫ������ʾ����



      return pHead;//����ͷָ��

}



//ִ�г��в���

void Delete_Linklist(LNode *pHead,int Lstart, int Ldel)

{

      int i,count=1;//countΪ������

      LNode *p, *temp;

      p=pHead;

      //�ҵ���M���������ڵ�λ��

      for(i=1;i<Lstart;i++)

             p=p->next;

      //ֻʣ1�����ʱ��ֹѭ��

      while(p->next!=p)

      {

             //�ҵ�Ҫ���еĺ��ӵ�λ��

             for(i=1;i<Ldel;i++)

             {

                    temp=p;

                    p=p->next;

             }

             //ִ�г��в���

             temp->next=p->next;//��*tempָ��*p����Ľ��

             printf("��%d�����е�С���ı��Ϊ��%d\n",count,p->num);

             free(p);//�ͷ�*p

             count++;

             //�����ߵ���һ��������Ϊ�µĵ�һ��������

             p=temp->next;

      }

      printf("��%d�����е�С���ı��Ϊ��%d\n",count,p->num);

      free(p);

      //�����˾����У�ͷ����ͷź󸳿�ֵ�������������ָ��

      pHead=NULL;

}



int main()

{

      int n,b,k;

      LNode *pHead=NULL, *p;//ִ�г�ʼ������

    //�����ַ��ĺϷ�����֤��ʱ����

      printf("������С���ĸ�����\n");

      scanf("%d",&n);

      printf("�����뿪ʼ������С����ţ�\n");

      scanf("%d",&b);

      printf("�����뱨����Ŀ��\n");

      scanf("%d",&k);

      p=Create_Linklist(pHead,n);//���ô���������

      Delete_Linklist(p,b,k);//����ɾ��������

      return 0;

}
*/
//�������ҵ
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
/*//ͼ���ӡ
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
/*//������
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
    printf("������Ϊ:%d",sum);
}
int even(int x)
{
    if(x%2==1){
        return 0;
    }else{return 1;}
}

*/

/*//������
#include<stdio.h>
int prime(int n);
int main()
{
    int m,n,t,i,sum=0,cnt=0;
    scanf("%d %d",&m,&n);
    if(m>n) {
        t=m;m=n;n=t;
    }
    printf("������:\n");
    for(i=m+1;i<=n;i++){
        if(prime(i)) {
                sum += i;
                cnt++;
                printf("%d\n",i);
        }
    }
    printf("������%d�������ǵĺ�Ϊ:%d\n",cnt,sum);
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
//ˮ�ɻ���
#include<stdio.h>
int Narcissistic(int n);
int pow(int a,int b);
int main()
{

    int i,m,t,n;
    scanf("%d %d",&m,&n);
    printf("ˮ�ɻ����У�\n");
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

//������ʵ��
/*//����ֵ����
#include<stdio.h>
int abs1(int n);
int main()
{
    int x;
    scanf("%d",&x);
    printf("x�ľ���ֵΪ��%d",abs1(x));
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
//�ݹ鷨��x��y����
/*
#include<stdio.h>
int xy(int x,int y);
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    printf("%d��%d����Ϊ:%d\n",m,n,xy(m,n));

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
/*//��������
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
    printf("������Ϊ:%d",sum);
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







