#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
 int element;
 struct node* lchild;
 struct node* rchild;
}Node,*NodePtr;

void insertNode(NodePtr *head,int data)
{
 if (*head==NULL)
 {
  *head=new Node;
  (*head)->element=data;
  (*head)->lchild=NULL;
  (*head)->rchild=NULL;
 }
 else
 {
  if (data<=(*head)->element)
  {
    insertNode(&((*head)->lchild),data);
  }
  else
  {
   insertNode(&((*head)->rchild),data);
  }
 }
}

NodePtr creatTree()
{
 NodePtr head=NULL;
 int data;
 scanf("%d",&data);
 while(data!=-1)
 {
  insertNode(&head,data);
  scanf("%d",&data);
 }
 return head;
}

int Search(NodePtr head,int key){
int sum;
int n=100;
while(head){
 if(head->element==key)
 return 1;
 else
 {
 if(head->element>key)
 return Search(head->rchild,key);
 else
 return Search (head->lchild,key);
 }
    sum++;
}
if(sum>n)
return 0;
}

int main()
{
 NodePtr head;
 int x;
 printf("请输入一串整数，空格隔开，以-1结尾\n");
 head=creatTree();
 printf("请输入要查找的x\n");
 scanf("%d",&x);
 if(Search(head,x)){
    printf("find it");
 }else{printf("not found");}
 return 0;
}
