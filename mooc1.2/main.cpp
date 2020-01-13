#include<stdio.h>
#define MAX 50
int main()
{
    int a[MAX],n,i,j,m;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    m=a[1]-a[0];
    if(m<0) m=-m;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
          if((a[j]-a[i])<m&&(a[j]-a[i])>=0){
            m=a[j]-a[i];
          }
        }
    }
    printf("%d\n",m);
}
