/*
#include <stdio.h>
#include <stdlib.h>
struct list
{
	int num;
	struct list *next;
};

typedef struct list list_single;

list_single *creat_list_tail(int n)//β�巨����һ������������һ��ͷָ��
{
	int i=0;
	list_single *head,*rear,*node;
	head=(list_single *)malloc(sizeof(list_single));
	rear=head;
	for(;i<n;i++)
	{
		node=(list_single *)malloc(sizeof(list_single));
		node->num=i+1;
		rear->next=node;//�½ڵ����β��
		rear=node;//�����Ҫ�������
	}
	rear->next=NULL;
	head->num=n;
	return head;
}

void list_delete_val(list_single *list,int val)
{
	list_single *pre,*temp;
	while(list!=NULL)
	{
		pre=list;//��¼���ڵĽڵ㣬�ҵ�����ͷָ��ûʹ����������˿��Դ�ͷָ���һ���ڵ㿪ʼ��ѯ
		temp=list->next;//��ѯ���µ�ǰ�ڵ�ָ����һ���ڵ��ֵ
		if(temp==NULL)
		{
			printf("û�ҵ���ؽڵ�val=%d\n",val);
			return;
		}
		if(temp->num==val) //�ҵ�Ŀ��ڵ�
		{
			pre->next=temp->next;
			free(temp);   //ɾ����ǵ��ͷ��ڴ�
			return;
		}
		list=list->next;
	}
}

void list_insert(list_single *list,int i,int x)
{
	list_single *target = (list_single *)malloc(sizeof(list_single));
	list_single *pre;
	int num=0;
	target->num=x;
	if(i<0)   //λ����СΪ0  ������С����
	{
		printf("λ���������\n");
		return ;
	}
	while(list!=NULL)
	{
		if(list->next==NULL)  //�����һ��λ�ú͵�һ��λ�����⴦��
		{
			printf("�������һ��λ��\n");
			list->next=target;//���һ��λ��ֱ�������һ���ڵ�ָ��Ŀ��ڵ㣬Ŀ��ڵ�ָ��NULL
			target->next=NULL;
			return;
		}
		else if(i==0) //��һ��λ��ֱ����ͷ���ָ��Ŀ��ڵ㣬Ŀ��ڵ�ָ��ԭ���ĵ�һ���ڵ�
		{
			pre=list->next;
			printf("���ǵ�һ��λ��\n");
			list->next=target;
			target->next=pre;
			return;
		}
		if(num==i)
		{
			pre=list->next;
			list->next=target;
			target->next=pre;
			break;
		}
		num++;
		list=list->next;
	}
}

int main()
{
    int a[4] = {0,1,2,3};
    list *p = creat_list_tail(49);
    for(int i=30;i<34;i++)
        list_insert(p,i,a[i-30]);

    while(p->next!=NULL)
    {
        printf("%d\n",p->num);
        p=p->next;
    }

            return 0;
}

*/








