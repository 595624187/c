#include<stdio.h>
#define N 10
int main()
{
    double a[N][2],b[N-1][N-1],t;
    int i,j,n,k=0;
    for(i=0;i<N;i++)
        for(j=0;j<2;j++)
        a[i][j]=-1;
    for(i=0;i<N-1;i++)
        for(j=0;j<N-1;j++)
        b[i][j]=-1;
    printf("请输入插值的个数(n<10):");
    scanf("%d",&n);
    printf("请输入插值的x：");
    for(i=0;i<n;i++){
        scanf("%lf",&a[i][0]);
    }
    printf("请输入插值的y：");
    for(i=0;i<n;i++){
        scanf("%lf",&a[i][1]);
    }
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        {
        b[i][j]=a[][]
        }

    for(i=0;i<n;i++){
        for(j=0;j<2;j++){
        printf("%.0lf ",a[i][j]);
        }
        printf("\n");
    }

}
