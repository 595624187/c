#include<stdio.h>
#include<stdlib.h>

int main()
{
    double *a,*b,y=0,x;
    int n,i;
    printf("Lagrange��ֵ��\n");
    printf("�������ֵ�ĸ�����");
    scanf("%d",&n);
    a = (double *)malloc((n+1)*sizeof(double));
    b = (double *)malloc((n+1)*sizeof(double));
    printf("��������%d������x:",n+1);
    for(i=0;i<=n;i++){
        scanf("%lf",a+i);
    }
    printf("��������%d������y:",n+1);
    for(i=0;i<=n;i++){
        scanf("%lf",b+i);
    }
    printf("���������������x:");
    scanf("%lf",&x);
    for(i=0;i<=n;i++){
        y+=1.0*b[i]*(x-a[(i+1)% (n+1)])*(x-a[(i+2)%(n+1)])/(a[i%(n+1)]-a[(i+1)%(n+1)])/(a[i%(n+1)]-a[(i+2)%(n+1)]);
    }
    printf("Lagrange������Ϊ:%lf\n",y);
    free(a);
    free(b);
}
