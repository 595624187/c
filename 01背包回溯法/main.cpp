#include<stdio.h>
#include<stdlib.h>
#define MAXN 20
int n=4;			    //4����Ʒ
int W=6;			    //��������Ϊ6
int w[]={0,5,3,2,1};	//���4����Ʒ����,�����±�0Ԫ��
int v[]={0,4,4,3,1};	//���4����Ʒ��ֵ,�����±�0Ԫ��
int rw;

//�������ʾ
int x[MAXN];			//������ս�
int maxv; 			    //������Ž���ܼ�ֵ
void Knapsack(int i,int tw,int tv,int rw,int op[]) //���0/1��������
{  if (i>n)				//�ҵ�һ��Ҷ�ӽ��
   {  if (tw==W && tv>maxv)		//�ҵ�һ�����������ĸ��Ž�,����
      {  maxv=tv;
         for (int j=1;j<=n;j++)
            x[j]=op[j];
      }
   }
   else					//��δ����������Ʒ
   {  if(tw+w[i]<=W){
       op[i]=1;				//ѡȡ��i����Ʒ
      Knapsack(i+1,tw+w[i],tv+v[i],rw-w[i],op);
   }
      op[i]=0;				//��ѡȡ��i����Ʒ,����
      if(tw+rw>W)
      Knapsack(i+1,tw,tv,rw-w[i],op);
   }
}
void dispasolution()         //������Ž�
{
   printf("���װ����ǣ�\n");
   for(int i=1;i<=n;i++)
   {
       if(x[i]==1)
	    printf("ѡȡ��%d����Ʒ\n",i);
   }
   printf("������=%d,�ܼ�ֵ=%d\n",W,maxv);
}
int main()
{
   int op[MAXN];  //�����ʱ��
   for(int i=1;i<=n;i++) rw+=w[i];
   Knapsack(1,0,0,rw,op);
   dispasolution();
   return 0;
}
