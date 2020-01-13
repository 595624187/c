#include <stdio.h>
#define MAX 100
int fun(int n)
{
    int sum=0;
        while(n/10!=0){
        sum+=n%10;
        n/=10;
    }
    sum+=n;
    return sum;
}
int fun1(int n)
{
    int i,t;
    for(i=2;i<n;i++){
        if(n%i==0){
            t=1;
            break;
        }else{
        t=0;}
    }
    return t;
}

int main(){
int j,k,n,n1,n2,i,t,sum1,sum;
int a[MAX];
//printf("输入N个整数：\n");
j=0;
scanf("%d",&a[j++]);
while(a[j-1]!=0){
    scanf("%d",&a[j++]);
}
for(k=0;k<j-1;k++){

if(fun1(a[k])==1){
n=a[k];t=1;
}else{continue;}

while(t){
    n1=n;n2=n;sum1=0;sum=0;
    sum1=fun(n1);
   // printf("sum1=%d",sum1);
    for(i=2; i<=n2; i++){
        while(n2!=i){
            if(n2%i==0){
            if(i/10==0){
                sum+=i;
            }else{
            sum+=fun(i);
            }
            n2=n2/i;
            }else
            break;
        }
    }
    sum+=fun(n2);
   // printf("sum=%d",sum);
    if(sum==sum1){
        t=0;
    }else{n++;}
}

printf("%d\n",n);
}
return 0;
}

