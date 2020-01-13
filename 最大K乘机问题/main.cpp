#include<stdio.h>
#define MAX 50
int w[MAX][MAX];
int m[MAX][MAX];
void MaxMult(int n,int k,int *a){
	int temp,max,i,j,d;
	for(i=1;i<=n;i++){
	  m[i][1]=w[1][i];
	}
	for(i=1;i<=n;i++){
		for(j=2;i<=k;j++){
		max=0;
		for(d=1;j<i;d++){
		 temp =m[d][j-1]*w[d+1][i];
		 if(temp>max){max=temp;}
		m[i][j]=max;
		}
	}
  }
}

int main()
{
	int c,n,k,i,j;
	printf("������λ���Ͷ���\n");
	scanf("%d %d",&c,&n);
	printf("���������%dλ��\n",c);
    scanf("%d",&k);
	int *a=new int[n];
	for(i=n;i>=1;i--){
	a[i]=c%10;
	c/=10;
	}
	for(i=1;i<=n;i++){
	w[i][i]=a[i];
	for(j=i+1;j<=n;j++){
		w[i][j]=w[i][j-1]*10+a[j];
	}
}
MaxMult(n,k,a);
printf("���K�˻�Ϊ��%d",m[n][k]);
return 0;
}
