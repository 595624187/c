//第六次c语言作业
/*
#include<stdio.h>
double fact_s(int n);

int main(void)
{
    int i,n;
    printf("Input n:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        printf("%3d!=%.0f\n",i,fact_s(i));
        return 0;
}
double fact_s(int n)
{
    static double f=1;
    f=f*n;
    return f;
}
*/
/*
#include<stdio.h>
#include"main.h"
int f(int a);
int main()
{
    int i;
    int n,a,sum=0;
    scanf("%d",&n);
    for (i=1 ; i <= n ;i ++){
        scanf("%d",&a);
        if(f(a)) sum++;
    }
    printf("素数有%d个",sum);
}
*/
/*

#include<stdio.h>
#include<math.h>
#define S (a+b+c)/2
#define AREA(a,b,c) sqrt(S*(S-a)*(S-b)*(S-c))


int main()
{
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    printf("该三角形面积为：%f\n",AREA(a,b,c));
}

*/
//第七次作业



/*
#include<stdio.h>
int main()
{
    int i,n,a[10],t=0,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        if(a[i]>cnt) {
            t=i;cnt=a[i];
        }
    }
    printf("最大值为%d，它的下标为%d",cnt,t);
}


*/
/*
#include<stdio.h>
int main()
{
    int a[10],t,i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(i=0;i<n/2;i++){
        t=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=t;
    }
    for(i=0;i<n;i++) printf("%d ",a[i]);
}
*/



/*
#include<stdio.h>
int main()
{
    int a[10],b[10],i,m,n,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    printf("共同的元素有：\n");
    for(j=0;j<n;j++){
        for(k=0;k<m;k++){
            if(a[j]==b[k]) printf("%d\n",a[j]);
        }
    }

}
*/

//第八次作业
/*
#include<stdio.h>
int main()
{
    int n,a[10][10],i,j,k=1,sum=0;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            a[i][j]=k++;
        }
    }
     for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
            printf("\n\n");
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            sum+=a[i][j];
        }
    }

    for(i=2;i<=n-2;i++){
        for(j=n-2;j>n-3;j--){
            sum+=a[i][j];
        }
    }

    printf("sum = %d",sum);
}
*/
/*
#include<stdio.h>
int main()
{
    int m,n,a[10][10],i,j,k=1,t;
    scanf("%d%d",&m,&n);
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            a[i][j]=k++;
        }
    }
     for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
            printf("\n\n");
    }
    for(k=1;k<=m;k++){
        for(i=0;i<n;i++){
            for(j=n-1;j>=0;j--){
                t=a[i][j];
                a[i][j+1]=a[i][j];
                a[i][j]=t;
            }
        }


    for(i=0;i<n;i++){
        a[i][0]=a[i][n];
    }
    }
    printf("\n\n");
     for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
            printf("\n\n");
    }
}

*/
// 5.  j>=1   i     6.  a[i][j]!=a[j][i]  found =1; found == 1

/*
#include<stdio.h>
int main()
{
    int a[6][6];
    int i,n,j,t=1;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(a[i][j]!=0){
             t=0;
            }
        }
        if(t==0) break;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%5d",a[i][j]);
        }
        printf("\n\n");
    }
    if(t){
        printf("YES");
    }else{
    printf("NO");
    }
}
*/


/*

#include<stdio.h>
int main()
{
    int a[6][6],i,j,m,n,sum[6];
    for(i=0;i<6;i++) sum[i]=0;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n\n");
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            sum[i]+=a[i][j];
        }
        printf("第%d行的和为：%d\n",i+1,sum[i]);
    }
}

*/
/*
//数组和
#include<stdio.h>
int Addshuzu(int a[],int b[],int c[]);
int main()
{
    int a[6]={1,2,3,4,5,6};
    int b[6]={2,4,6,8,10,12};
    int c[6]={0};
    int i;
    for(i=0;i<6;i++) printf("%2d  ",a[i]);
        printf("\n");
    for(i=0;i<6;i++)printf("%2d  ",b[i]);
        printf("\n");
    Addshuzu(a,b,c);
    printf("  数组和为：\n");
    for(i=0;i<6;i++)printf("%2d  ",c[i]);
}
int Addshuzu(int a[],int b[],int c[])
{
    int i;
    for(i=0;i<6;i++) c[i]=a[i]+b[i];
    return 0;
}
*/

/*
//最大及最小的位置
#include<stdio.h>
void find(int a[],int *max,int *min,int *m,int *n);
int main()
{
    int a[6]={5,3,15,45};
    int max,min,m,n,i;
    find(a,&max,&min,&m,&n);
    for(i=0;i<6;i++) printf("%d  ",a[i]);
    printf("\nmax=%d位置是：%d\n",max,m+1);
    printf("min=%d位置是：%d\n",min,n+1);
}
void find(int a[],int *max,int *min,int *m,int *n)
{
    int i,am,an,max1,min1;
    max1=min1=a[0];
    am=an=0;
    for(i=1;i<6;i++)
    {
        if(a[i]>max1) {
        max1=a[i];am=i;
        }

        if(a[i]<min1){
        min1=a[i];an=i;
        }
    }
    *max=max1;*min=min1;
    *m=am;*n=an;
}
*/

/*
//串长度
#include <stdio.h>
int lenstr(const char* str)
{
    int i = -1;
    while (str[++i]);
    return i;
}
int main()
{
    char p[1000];
    printf("输入一个字符串:");
    gets(p);
    printf("长度为: %d\n", lenstr(p));
    return 0;
}
*/
/*
#include<stdio.h>
#include<string.h>
int main()
{
char a[100];
char b[100];
int i,j,l1,l2;
printf("输入第一个字符串：");
gets(a);
printf("输入第二个字符串：");
gets(b);
l1 = strlen(a);
l2 = strlen(b);
    for(i=0;b[i]!='\0';i++){
      a[i+l1] = b[i];
    }
 a[l1+l2] = '\0';
 printf("连接后的字符串为：");
 puts(a);
}
*/
/*
#include<stdio.h>
int main()
{
	void revStr(char *);
	char str[80];
	printf("输入一个字符串: ");
	gets(str);
	revStr(str);
	printf("转置后的字符串: %s\n",str);
}
void revStr(char *str)
{
	int i,len;
	char tmp;
	for(len=0;str[len];len++);
	for(i=0;i<len/2;i++)
	{
		tmp=str[len-i-1];
		str[len-i-1]=str[i];
		str[i]=tmp;
	}
}
*/
/*
#include <stdio.h>
int main()
{
int i, j = 0;
char ch;
char str[100];
while ((ch = getchar()) != '\n')
{
str[j++] = ch;
}

    for (i=0; i<j; i++){
        if (' ' != str[i]){
        printf("%c", str[i]);
        }
    }
}
*/
/*
#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,a[1001],m,n=0;
    scanf("%d",&m);
    for(i=1;i<=m;i++) a[i]=i;
    for(i=2;i<sqrt(m);i++){
        for(j=i+1;j<=m;j++)
        {
            if(a[j]!=0 && a[i]!=0)
            if(a[j]%a[i]==0)
                a[j]=0;
                }
    }
    for(i=2;i<=m;i++)
      { if(a[i]!=0)
         {printf("%5d",a[i]);
          n++;
          if(n%10==0) printf("\n");
}

       }

}

*/
/*


#include<stdio.h>
int main()
{
    char s[80]={1,2,3,4,5,6,7,8,'\0'};
    int i,j;
    char c='5';
    //gets(s);
    for(i=j=0;s[i]!='\0';i++)
        if(s[i]!='c') for(j=i;s[j]!='\0';j++) s[j]=s[j+1];
    s[j]='\0';
    puts(s);
}


*/
//回文判断
/*
#include<stdio.h>
int main()
{
    int i,k;
    char line[80];
    printf("Enter a string:");
    k=0;
    while((line[k] = getchar())!='\n')
        k++;
    line[k]='\0';
    i=0;k--;
    while(i<k){
        if(line[i]!=line[k])
            break;
        i++;k--;
    }
    if (i>=k)
        printf("It is a plalindrome\n");
    else
        printf("It is not a plalindrome\n");
    return 0;
}
*/
//第九次作业
/*
#include<stdio.h>
int main()
{
    char line[80];
    int i=0,j,cnt=0;
    while((line[i]=getchar())!='\n') i++;
    line[i]='\0';
    for(j=0;j<i;j++){
        switch(line[j]){
        case 'A':cnt++;break;
        case 'E':cnt++;break;
        case 'I':cnt++;break;
        case 'O':cnt++;break;
        case 'U':cnt++;break;
        }
    }
    printf("共有%d个大写辅音",i-cnt);


}

*/


/*
#include<stdio.h>
int main()
{
    char line[80];
    int i=0,j=0;
    while((line[i]=getchar())!='\n') i++;
    line[i]='\0';
    for(j=0;j<i;j++){
    if(line[j]>='A'&&line[j]<='Z'){
        line[j]=155-line[j];
    }
    }
    puts(line);
}

*/
/*
#include <string.h>
#include <stdio.h>
char a[80];
int b[80];
int main()
{
int j=0,i=0;
while((a[i]=getchar())!='#') i++;
    for( i=0; a[i]!='#'; i++){
        if( (a[i]>='0' && a[i]<='9') || (a[i]>='a' && a[i]<='f') || a[i]>='A' && a[i]<='F' ) break;
    }
int flag=0;
    for(int k=0;k<i;k++)
    if(a[k]=='-') {
            flag++;
            break;
        }

    for(i=0; a[i]!='#'; i++){
        if(a[i]>='A' && a[i]<='Z')
            a[i]+=32;
        if( (a[i]>='0' && a[i]<='9') )
        {
            b[j++]=a[i]-'0';
        }
        if(a[i]>='a' && a[i]<='f')
        {
            b[j++]=a[i]-'a'+10;
        }
    }
        double sum=0;
        int jz=1;
        for(int i=j-1; i>=0; i--) {
                sum += jz*b[i]; jz*=16;
                }
        if(sum!=0){
                if(flag)printf("-");
            }
            printf("%.1lf\n",sum);

     return 0;
}

*/
//第十次作业
/*
#include<stdio.h>
int main(){
char a;
scanf("%c",&a);
printf("%c\n",a-32);
}
*/
/*
#include<stdio.h>
int main(){
    int b,a;
    scanf("%d",&a);
    b=a/100+a%100/10*10+a%10*100;
    printf("%d\n",b);
    }
*/
/*
#include<stdio.h>
int main()
{
    int i,sum=0;
    for(i=1000;i<=3000;i++){
        if(i%13==0&&i%27==0){
            sum++;
        }
    }
    printf("%d",sum);
}
*/
/*
#include<stdio.h>
int main()
{
    char str[19],str1[9];
    int i,k=0;
    gets(str);
    for(i=0;i<19;i++){
        if(i>=6&&i<=13){
            str1[k++]=str[i];
        }
    }
    puts(str1);
}
*/
//第十一次作业
/*

#include<stdio.h>
void sum_diff(float op1,float op2,float *psum,float *pdiff);
int main()
{
    float a,b,sum,diff;
    scanf("%f%f",&a,&b);
    sum_diff(a,b,&sum,&diff);
    printf("sum=%f\t diff=%f\n",sum,diff);
}

void sum_diff(float op1,float op2,float *psum,float *pdiff)
{
    *psum = op1+op2;
    *pdiff = op1-op2;
}
*/


/*
#include<stdio.h>
void dplitfloat(float x, int *intpart ,float *fracpart);
int main()
{
    float n,f;
    int i;
    scanf("%f",&n);
    dplitfloat(n,&i,&f);
    printf("intpart=%d\nfloatpart=%f\n",i,f);
}
void dplitfloat(float x, int *intpart ,float *fracpart)
{
    *intpart=(int)x;
    *fracpart=x-*intpart;
}
*/
/*
#include<stdio.h>
int main()
{
    int a[20],i=0,t;
    int j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
        for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    printf("\n");
    for(j=1;j<n;j++){
        for(k=0;k<n-j;k++){
            if(a[k]>a[k+1]){
                t=a[k];
                a[k]=a[k+1];
                a[k+1]=t;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }

}
*/
/*
//example
#include<stdio.h>
int main()
{
    int a[100],*p,sum=0;
    for(int i=0;i<100;i++) a[i]=2*i;
    int i=0;
    for(p=a;p<=&a[99];p++){
        sum+=*p;i++;
        if(a[i]==100){
            printf("%d\n",*p);
        }
    }
    printf("%d",sum);

}
*/
/*
#include<stdio.h>
int search(int list[],int n,int x);
int main ()
{
    int i,n,a[11],x,result;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    printf("\n请输入要查找的数字：");
    scanf("%d",&x);
    result=search(a,n,x);
    if(result>-1){
        printf("x的下标为：%d",result);
    }else
    {
        printf("Not found");
    }

}
int search(int list[],int n,int x)
{
    int *p,i=0,a;
    p=list;
    for(p=list;p<&list[n];p++){
        i++;
        if(*p==x) {
                a=i;
                break;
        }else{
                a=-1;
        }
    }
    return a;
}
*/

/*
#include<stdio.h>
int main()
{
    int a[20],*p;
    int i,j,n,m;
    scanf("%d",&n);
    printf("请输入这n个数：\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("\n");
    printf("请输入移动位数：\n");
    scanf("%d",&m);
    for(i=0;i<m;i++){
        for(j=n;j>0;j--){
            a[j]=a[j-1];
        }
        a[0]=a[n];
    }
    for(i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
}
*/
/*
#include <stdio.h>
int main()
  {
    int m,n,i,j,k=0;
    int a[100]={0};
    printf("请输入总人数n和报的数字m： \n");
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++) a[i] = i+1;
        while (n >= 1)
        {
            i = (i + m - 1) % n;
            k++;
            printf("第%d个出圈的是%d\n",k,a[i]);
            for(j = i+1; j < n; j++) a[j-1] = a[j];
            n--;
            if(i == n) i = 0;
        }
  }
*/


/*
#include<stdio.h>
int getMaxbook(struct books book[],double price);
int getMinbook(struct books book[],double price);
void printBook(struct books book[],char name[],double price,int max,int min);
    struct books{
    char name[10];
    double price;
    };
    struct books book[10];
 int main()
    {
        int i,max=0,min=0;
        double price;
        char name[10];
        for(i=0;i<10;i++){
            printf("第%d本书的名字为：\n",i+1);
            gets(book[i].name);
            printf("第%d本书的价格为：\n",i+1);
            scanf("%lf",&book[i].price);
            getchar();

        }
        max = getMaxbook(book,price);
        min = getMinbook(book,price);
        printBook(book,name,price,max,min);
    }

int getMaxbook(struct books book[],double price)
{
        int i,t=0;
        double m = book[0].price;
        for(i=1;i<10;i++){
            if(book[i].price>m){
                m=book[i].price;
                t=i;
            }
        }
        return t;
}
int getMinbook(struct books book[],double price)
{
        int i,t=0;
        double m = book[0].price;
        for(i=1;i<10;i++){
            if(book[i].price<m){
                m=book[i].price;
                t=i;
            }
        }
        return t;
}
void printBook(struct books book[],char name[],double price,int max,int min)
{
        printf("The most expensive book:\n");
        printf("Name:%s  Price:%.2lf\n",book[max].name,book[max].price);
        printf("The most cheap book:\n");
        printf("Name:%s  Price:%.2lf\n",book[min].name,book[min].price);
}



*/

/*
#include<stdio.h>
#include<string.h>
struct Worker{

	char name[10];
	char num[8];

};
void Sort(struct Worker wk[]){				//排序函数

	struct Worker temp;
	for(int i=0;i<5;i++){
		int k = i;
		for(int j=i+1;j<5;j++){
			if(wk[j].num>wk[k].num){
				k = j;
			}//end if
		temp = wk[k];
		wk[k] = wk[i];
		wk[i] = temp;
		}//end for

	}//end for
	for(int t=0;t<5;t++){

		printf("%s %s\n",wk[t].name,wk[t].num);
	}
}
void Select(struct Worker wk[],char n[8]){

	int low = 0,high = 7;
	int mid;
	while(low<high){
		mid = (low+high)/2;
		if(wk[mid].num == n) printf("%s\n",wk[mid].name);
		else if(wk[mid].num>n) low = mid + 1;
		else if(wk[mid].num<n) high = mid - 1;
	}//end while
}

int main(){
	struct Worker wk[5];
	printf("Please enter name and number\n");
	for(int i=0;i<5;i++){
		gets(wk[i].name);
		gets(wk[i].num);
	}//end for
	printf("----------------------------------------\n");
	for(int j=0;j<5;j++){
		puts(wk[j].name);
		puts(wk[j].num);
	}//end for
	printf("----------------------------------------\n");
	printf("The order is\n");
	Sort(wk);
	printf("----------------------------------------\n");
	printf("Please enter the number\n");
	struct Worker temp;
	gets(temp.num);
	puts(temp.num);
	Select(wk,temp.num);


}

*/






