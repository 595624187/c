#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXN 51
#define MAXK 10
static long m[MAXK][MAXN];
static long w[MAXN][MAXN];
void maxdp(int n,int k,int *a)
{
    int i,j,d,h,q,t,s;
    long temp,max;
    for(i=1;i<=n;i++)
        m[i][1]=w[1][i];;
    for(i=1;i<=n;i++)
    for(j=2;i<=k;j++){
        max=0;
        for(d=1;d<i;d++)
            if((temp=m[d][j-1]*w[d+d][i])>max)
            max=temp;
        m[i][j]=max;
    }
}
int main()
{
    int n,k,i,j;
    int a[MAXN]={0},la=0;
    char c;
    scanf("%d %d",&n,&k);
    while((c=getchar())!='\n')
        a[++la]=c-'0';
    for(i=1;i<=n;i++){
        w[i][i]=a[i];
        for(j=i+1;j<=n;j++)
            w[i][j]=w[i][j-1]*10+a[j];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
        printf("%5d",w[i][j]);
        printf("\n");
    }
    maxdp(n,k,a);
    printf("%ld",m[n][k]);
    getchar();
}
