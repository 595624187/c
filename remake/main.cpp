/*
#include <stdio.h>
#include <stdlib.h>
struct list
{
	int num;
	struct list *next;
};

typedef struct list list_single;

list_single *creat_list_tail(int n)//尾插法创建一个链表，并返回一个头指针
{
	int i=0;
	list_single *head,*rear,*node;
	head=(list_single *)malloc(sizeof(list_single));
	rear=head;
	for(;i<n;i++)
	{
		node=(list_single *)malloc(sizeof(list_single));
		node->num=i+1;
		rear->next=node;//新节点插在尾巴
		rear=node;//这点需要着重理解
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
		pre=list;//记录现在的节点，我的链表头指针没使用数据域，因此可以从头指针后一个节点开始查询
		temp=list->next;//查询的事当前节点指向下一个节点的值
		if(temp==NULL)
		{
			printf("没找到相关节点val=%d\n",val);
			return;
		}
		if(temp->num==val) //找到目标节点
		{
			pre->next=temp->next;
			free(temp);   //删除后记得释放内存
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
	if(i<0)   //位置最小为0  不可能小于零
	{
		printf("位置输入错误\n");
		return ;
	}
	while(list!=NULL)
	{
		if(list->next==NULL)  //在最后一个位置和第一个位置特殊处理
		{
			printf("这是最后一个位置\n");
			list->next=target;//最后一个位置直接让最后一个节点指向目标节点，目标节点指向NULL
			target->next=NULL;
			return;
		}
		else if(i==0) //第一个位置直接让头结点指向目标节点，目标节点指向原来的第一个节点
		{
			pre=list->next;
			printf("这是第一个位置\n");
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








