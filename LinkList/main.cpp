#include<stdio.h>
#include<stdlib.h>
typedef struct LinkList
{
      int data;
      struct LinkList *next;
}LinkList;

LinkList *Create_node(int value)
{
      LinkList *p;
      p=(LinkList *)malloc(sizeof(LinkList));
      p->data=value;
      p->next=NULL;
      return p;

}
LinkList *Create_LinkList(LinkList *pH, int num)
{
      int k;
      LinkList *p,*temp;
      for(k=1;k<=num;k++)
      {
             p=Create_node(k);
             if(pH==NULL)
             {
                    temp=p;
                    pH=p;
                    temp->next=pH;
             }
             else
             {
                    p->next=temp->next;
                    temp->next=p;
                    temp=p;
             }
      }

      return pH;
}


void Delete_LinkList(LinkList *pH,int Lstart, int Ldel)
{
      int i,count=1;
      LinkList *p, *temp;
      /*
      p=pH;
*/
      for(i=1;i<Lstart;i++) p=p->next;
      while(p->next!=p)
      {
             for(i=1;i<Ldel;i++)
             {
                    temp=p;
                    p=p->next;
             }

             temp->next=p->next;
             printf("��%d�����е��˵ı��Ϊ��%d\n",count,p->data);
             free(p);
             count++;
             p=temp->next;
      }
      printf("��%d�����е��˵ı��Ϊ��%d\n",count,p->data);
      free(p);
      pH=NULL;
}
int main()
{
      int n,b,k;
      LinkList *pH=NULL, *p;
      printf("�������˵ĸ�����\n");
      scanf("%d",&n);
      printf("�����뿪ʼ�������˱�ţ�\n");
      scanf("%d",&b);
      printf("�����뱨����Ŀ��\n");
      scanf("%d",&k);
      p=Create_LinkList(pH,n);
      Delete_LinkList(p,b,k);
      return 0;
}
