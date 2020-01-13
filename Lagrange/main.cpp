#include<stdio.h>
#include<stdlib.h>

int main()
{
    double *a,*b,y=0,x;
    int n,i;
    printf("Lagrange插值法\n");
    printf("请输入插值的个数：");
    scanf("%d",&n);
    a = (double *)malloc((n+1)*sizeof(double));
    b = (double *)malloc((n+1)*sizeof(double));
    printf("请输入这%d个数的x:",n+1);
    for(i=0;i<=n;i++){
        scanf("%lf",a+i);
    }
    printf("请输入这%d个数的y:",n+1);
    for(i=0;i<=n;i++){
        scanf("%lf",b+i);
    }
    printf("请输入这个待求数x:");
    scanf("%lf",&x);
    for(i=0;i<=n;i++){
        y+=1.0*b[i]*(x-a[(i+1)% (n+1)])*(x-a[(i+2)%(n+1)])/(a[i%(n+1)]-a[(i+1)%(n+1)])/(a[i%(n+1)]-a[(i+2)%(n+1)]);
    }
    printf("Lagrange计算结果为:%lf\n",y);
    free(a);
    free(b);
}
