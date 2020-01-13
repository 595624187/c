//习题8
//P215
//程序设计2
/*
#include<stdio.h>
int main(){
    int i,n,res,x;
    int a[10];
    int search(int list[],int n,int x);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&x);
    res = search(a,n,x);
    if(res!=-1)
        printf("index = %d\n",res);
    else
        printf("Not found\n");

}
int search (int list[],int n,int x){
    int i;
    for(i=0;i<n;i++)
        if(list[i]==x) return i;
        return -1;

}
*/
//程序设计3
/*
#include<stdio.h>
void mov(int *x,int n,int m);
int main()
{
    int i,m,n;
    int a[80];
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mov(a,n,m);
    printf("After move:");
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
    printf("\n");
}
void mov(int *x,int n,int m){
    int i,j,k;
    for(i=1;i<m;i++){
        k=x[n-1];
        for(j=n-1;j>0;j--)
            x[j]=x[j-1];
        x[0]=k;
    }
}
*/
//程序设计4
/*
#include<stdio.h>
#define MAX 20
void Count(int n,int m,int out[]);
int main()
{
    int out[MAX],n,m;
    int i;
    scanf("%d %d",&n,&m);
    Count(n,m,out);
    for(i=0;i<n;i++){
        printf("%d",out[i]);
    }
    printf("\n");
    return 0;
}
void Count(int n,int m,int out[])
{
    int i,count,no,num[MAX];
    count = no = 0;
    int *p=num;
    for(i=0;i<n;i++)
        num[i]=i+1;
    while(no<n-1){
        if(*p!=0) count ++;
    if(count ==m ){
        no ++;
        out[no-1]=*p;
        *p=0;
        count =0;
    }
    p++;
    if(p==num+n) p=num;
}
p=num;
while(*p==0)
    p++;
out[no]=*p;
}

*/
//程序设计5
/*
#include<stdio.h>
#include<string.h>
int main()
{
    char s[80],t[80];
    int m;
    void strmcpy(char *s,char *t,int m);
    gets(t);
    scanf("%d",&m);
    getchar();
    if(strlen(t)<m)
        printf("error input");
    else {
        strmcpy(s,t,m);
        puts(s);
    }
}
void strmcpy(char *s,char *t,int m)
{
    t=t+m-1;
    while(*t!='\0'){
        *s=*t;
        s++;t++;
    }
    *s='\0';
}
*/
//程序设计6
/*
#include<stdio.h>
int main()
{
    char c;
    char str[80];
    void delchar(char *str,char c);
    gets(str);
    scanf("%c",&c);;
    getchar();
    delchar(str,c);
    printf("result:");
    puts(str);
}
void delchar(char *str, char c)
{
    int i,j;
    i=j=0;
    while(str[i]!='\0'){
        if(str[i]!=c){
            str[j]=str[i];
            j++;
        }
        i++;
    }
    str[j]='\0';
}
*/
//程序设计7
/*
#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,index;
    char sx[5][80],stemp[80];
    for(i=0;i<5;i++)
        scanf("%s",sx[i]);
    for(i=0;i<4;i++){
        index = i;
        for(j=i+1;j<5;j++)
        if(strcmp(sx[j],sx[index])<0){
            index=j;
        }
        strcpy(stemp,sx[i]);
        strcpy(sx[i],sx[index]);
        strcpy(sx[index],stemp);
    }
    printf("After sorted:\n");
    for(i=0;i<5;i++)
    puts(sx[i]);
    return 0;
}
*/
//程序设计8
/*
#include<stdio.h>
int main()
{
    char s[80];
    int mirror(char *p);
    gets(s);
    if(mirror(s)!=0)
        printf("YES\n");
    else
        printf("NO\n");

}
int mirror(char *p)
{
    char *q;
    q=p;
    while(*q!='\0')
    q++;
    q--;
    while(p<q){
        if(*p!=*q)
            return 0;
        p++;q--;
    }
    return 1;
}
*/
//程序设计9
/*
#include<Stdio.h>
int main()
{
    char s[80];
    char *p;
    int blank,digit,lower,other,upper;
    gets(s);
    upper = lower = blank = digit = other = 0;
    for(p=s;*p!='\0';p++)
        if(*p>='A'&&*p<='Z')
        upper ++;
    else if(*p>='a'&&*p<='z')
        lower++;
    else if(*p>='0'&&*p<='9')
        digit ++;
    else if(*p==' ')
        blank ++;
    else
        other ++;
    printf("upper:%d lower:%d blank: %d digit: %d other: %d\n",upper,lower,blank,digit,other);
}

*/

//程序设计10
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    float *p,sum,max,min,avg;
    printf("input students' number n:");
    scanf("%d",&n);
    if((p=(float*)calloc(n,sizeof(float)))==NULL){
        printf("Not able to allocate memory.\n");
        exit(1);
    }
    sum=0.0;
    max=-1;min=1000;
    printf("input %d students' scores:",n);
    for(i=0;i<n;i++)
    {
        scanf("%f",p+i);
        sum += *(p+i);
        if(min>*(p+i))
            min = *(p+i);
        if(max<*(p+i))
            max= *(p+i);
    }
    avg = sum/n;
    printf("\nThe avg is %.2f  ,max is %.2f  ,min is %.2f\n",avg,max,min);
    free(p);
    return 0;
}
*/
//p262
//程序设计11
/*
#include<stdio.h>
#include<math.h>
int fun(int n);
int main()
{
    int n;
    printf("input n:");
    scanf("%d",&n);
    printf("total = %d \n",fun(n));
    return 0;
}
int fun(int n)
{
    int i,d = 0;
    for(i=101;i<n;i++)
    if(((int)sqrt(i)*(int)sqrt(i))==i){
        if(i/100==(i/10)%10||i/100==i%10||(i/10)%10==i%10)
            d++;
    }
    return d;
}

*/

//程序设计12
/*
#include<stdio.h>
double fact(int n);
int main()
{
    int i,n;
    double sum;
    scanf("%d",&n);
    sum = 0;
    for(i=1;i<=n;i++){
        sum+= fact(i);
    }
    printf("%.0f\n",sum);
    return 0;
}
double fact(int n)
{
    double result;
    if(n==1||n==0)
        result = 1;
    else
        result = n*fact(n-1);
    return result;
}
*/
//程序设计13
/*
#include<stdio.h>
double fun (double x,int n);
int main ()
{
    int n;
    double x,root;
    scanf("%lf%d",&x,&n);
    root = fun(x,n);
    printf("Root = %0.2f\n",root);
    return 0;
}
double fun(double x,int n)
{
    if(n==1)
        return x;
    else if(n==0)
        return 1;
    else
        return x*fun(x,n-1);
}
*/
//程序设计14
/*
#include<stdio.h>
#include<math.h>
double f(double x,int n)
{
    if(n==1) return x;
    return pow(-1,n-1)*pow(x,n)+f(x,n-1);

}
int main()
{
    int n;
    double x;
    scanf("%lf %d",&x,&n);
    printf("%lf\n",f(x,n));
    return 0;
}
*/

//程序设计15
/*
#include<stdio.h>
int ack(int m,int n);
int main()
{
    int m,n;
    int result;
    scanf("%d%d",&m,&n);
    result=ack(m,n);
    printf("Ackerman(%d,%d)=%d\n",m,n,result);
    return 0;
}
int ack(int m,int n)
{
    if(m==0) return n+1;
    else if(n==0) return ack(m-1,1);
    else return ack(m-1,ack(m,n-1));
}
*/
//程序设计16
/*
#include<stdio.h>
int fib(int n);
int main()
{
    int n;
    scanf("%d",&n);
    printf("fib(%d)=%d\n",n,fib(n));
    return 0;
}
int fib(int n)
{
    int res;
    if(n==0)
        res = 0;
    else if (n==1)
        res = 1;
    else
        res = fib(n-2)+fib(n-1);
    return res;
}
*/

//程序设计17
/*
#include<stdio.h>
void dectobin(int n);

int main()
{
    int i,n;
    scanf("%d",&n);
    dectobin(n);
    return 0;
}
void dectobin(int n)
{
    if(n<2)
        printf("%d",n);
    else{
        dectobin(n/2);
        printf("%d",n%2);
    }

}
*/

//程序设计18
/*
#include<stdio.h>
void inorder(int n);
int main()
{
    int n;
    scanf("%d",&n);
    inorder(n);
    return 0;
}
void inorder(int num)
{
    if(num <10)
        printf("%d\n",num);
    else
    {
        inorder(num/10);
        printf("%d\n",num%10);
    }
}
*/
//p294
//程序设计19
/*
#include<stdio.h>
int main()
{

    char*months[]={"January","February","March","April",
    "May","June","July","August","September","October","November","December"};
    int n;
    scanf("%d",&n);
    if(n<1||n>12) printf("wrong input!\n");
    else
        printf("%s\n",months[n-1]);
    return 0;
}
*/
