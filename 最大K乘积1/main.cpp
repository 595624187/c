#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define MAXN 51
#define MAXK 10
int mul[MAXN][MAXN]={{0,0}} ;
int sub[MAXN][MAXN]={{0,0}} ;

void max_k_mul(int n,int k,char *a)
{
    int i,j,d;
    long temp,max;
    for(i=0; i< n ; i++)
{
    mul[i][0] = sub[0][i];
}
for(i=0 ; i< n ; i++)
  for(j=1; j< k ; j++)
{
 max = 0;
 for(d=0; d < i ; d++)
 {
    temp= mul[d][j-1]*sub[d+1][i];
     if (temp > max)
     {
     max = temp;
     }
 }
 mul[i][j] = max ;
}
}

int main()
{
int n=0,k=0,i,j,t;
char a[MAXN],b[MAXN];
string str[MAXN];
ifstream read("D:\\input.txt");
read>>n>>k>>a;
read.close();
for(i=0 ; i< n; i++)
{
    sub[i][i]= a[i]-'0';
    for(j=i+1 ; j< n; j++)
    sub[i][j] = sub[i][j-1]*10 +( a[j]-'0');
}
max_k_mul(n,k,a);
cout<<"最大乘积为:"<<mul[n-1][k-1]<<endl ;
ofstream out("D:\\output.txt");
if(!out)
{
cout<<"文件打开失败!"<<endl;
return -1;
}
out<<mul[n-1][k-1];
return  0;
}

