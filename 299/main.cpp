//第十三次作业
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    FILE *fp;
    long num,num1,num2;
    char name[20],name1[20],name2[20];
    int i,score,max,min;
    if((fp=fopen("e:\\f12-1.txt","r"))==NULL){
        printf("File open error!\n");
        exit(0);
    }
        fscanf(fp,"%ld %s %d",&num,name,&score);
        max=min=score;
        strcpy(name1,name);
        strcpy(name2,name);
        num1=num2=num;
        printf("%ld %s %d\n",num,name,score);
    for(i=1;i<5;i++){
        fscanf(fp,"%ld %s %d",&num,name,&score);
        if(score>max) {
                max = score;
                strcpy(name1,name);
                num1=num;
        }
        if(score<min) {
                min = score;
                strcpy(name2,name);
                num2=num;
        }
        printf("%ld %s %d\n",num,name,score);
    }
     printf("\nMax:\n%ld %s %d\n",num1,name1,max);
     printf("Min:\n%ld %s %d\n",num2,name2,min);
    if(fclose(fp)){
        printf("Can not close the file!\n");
        exit(0);
    }

}
*/
/*
#include<stdio.h>
#include<stdlib.h>
struct user{
    char name[10];
    char password[10];
};
void encrypt(char *s);
int main()
{
    FILE *fp1,*fp2;
    int i;

    struct user users;
    if((fp1=fopen("e:\\f12-2.txt","r"))==NULL){
        printf("File open error!\n");
        exit(0);
    }
    if((fp2=fopen("e:\\temp.txt","w"))==NULL){
        printf("File open error!\n");
        exit(0);
    }
    for(i=0;i<5;i++){
        fscanf(fp1,"%s %s",users.name,users.password);
        printf("Before:  %s %s\n",users.name,users.password);
        encrypt(users.name);
        encrypt(users.password);
        printf("After:   %s %s\n",users.name,users.password);
        fprintf(fp2,"%s %s\n",users.name,users.password);
    }
    if(fclose(fp1)){
        printf("Can not close the file!\n");
    }
    if(fclose(fp2)){
        printf("Can not close the file!\n");
    }

}
void encrypt(char *s){
    for(;*s!='\0';s++){
        if(*s=='z') *s='a';
        else *s=*s+1;
    }
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fp1,*fp2,*fp3;
    char ch;
    int num=0;
    if((fp1=fopen("e:\\f12-2.txt","r"))==NULL){
        printf("File open error!\n");
        exit(0);
    }
    if((fp2=fopen("e:\\f12-3.txt","w"))==NULL){
        printf("File open error!\n");
        exit(0);
    }
    while(!feof(fp1)){
        ch = fgetc(fp1);
        if(ch!=EOF) fputc(ch,fp2);
    }
        if(fclose(fp2)){
        printf("Can not close the file!\n");
        exit(0);
    }
        if(fclose(fp1)){
        printf("Can not close the file!\n");
        exit(0);
    }
    if((fp3=fopen("e:\\f12-3.txt","r"))==NULL){
        printf("File open error!\n");
        exit(0);
    }

    while(!feof(fp3)){
        ch=fgetc(fp3);
        if(ch!=EOF) num++;

    }
    printf("该文件中共有%d个字符",num);


    if(fclose(fp3)){
        printf("Can not close the file!\n");
        exit(0);
    }
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char ch;
    int c=0,i=0,a=0;
    if((fp=fopen("e:\\f13-1.txt","r"))==NULL){
        printf("File open error!\n");
            exit(0);
    }
    while(!feof(fp)){
        ch = fgetc(fp);
        printf("%c",ch);
        if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z') c++;
        else if(ch>='0'&&ch<='9') i++;
        else a++;
    }
    printf("\n\nchar:%d\nint:%d\nfuhao:%d\n",c,i,a);
    if(fclose(fp)){
        printf("Can not close !");
        exit(0);
    }
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    FILE *fp;
    char str[30];
    char str1[30]="for";
    char ch;
    int i=0;
    if((fp=fopen("e:\\f13-2.txt","r"))==NULL){
        printf("File open error!\n");
        exit(0);
    }
    while(!feof(fp)){
        fgets(str,30,fp);
        for(i=0;i<strlen(str);i++){
            if(str[i]=='f'&&str[i+1]=='o'&&str[i+2]=='r')
                puts(str);
        }
    }
    if(fclose(fp)){
        printf("Can not close the file!");
        exit(0);
    }
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fp1,*fp2;
    char str[30];
    int i;
    char ptr='\\';
    if((fp1=fopen("e:\\hello.c","r"))==NULL){
        printf("File open error!\n");
        exit(0);
    }
    if((fp2=fopen("e:\\new_hello.c","w"))==NULL){
        printf("File open error!\n");
        exit(0);
    }

    while(!feof(fp1)){
        fgets(str,30,fp1);
        for(i=0;i<strlen(str);i++){
        if(str[i]!='\0'){
        fputc(str[i],fp2);
        putchar(str[i]);
        if(str[i+1]=='\\')
        break;
        }

    }

    }


    if(fclose(fp1)){
        printf("Can not close the file!");
        exit(0);
    }
    if(fclose(fp2)){
        printf("Can not close the file!");
        exit(0);
    }
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fp1,*fp2;
    if((fp1=fopen("e:\\f12-3.txt","r"))==NULL){
        printf("File open error!\n");
        exit(0);
    }
    if((fp2=fopen("e:\\f12-3.txt","w"))==NULL){
        printf("File open error!\n");
        exit(0);
    }
    char ch;
    while((ch=fgetc(fp1))!='\0'){

        fputc(ch,fp2);
    }


        if(fclose(fp1)){
        printf("Can not close the file!");
        exit(0);
    }
     if(fclose(fp2)){
        printf("Can not close the file!");
        exit(0);
    }
}
*/
/*
//第五次实验
#include<stdio.h>
#include<stdlib.h>
   struct student {
        int num;
        float score;
        double grade;
        struct student *next;
    };

struct student *insert(struct student *head,struct student* stu)
{
        struct student *ptr,*ptr1,*ptr2;
        ptr2 = head;
        ptr = stu;
        if(head ==NULL ){
            head = ptr;
            head -> next = NULL;
        }
        else{
            while((ptr->num>ptr2->num)&&(ptr2->next!=NULL)){
                ptr1=ptr2;
                ptr2 = ptr2->next;
            }
            if(ptr->num<=ptr2->num){
                if(head == ptr2) head = ptr;
                else ptr1->next = ptr;
                ptr ->next = ptr2;
            }
            else{
                ptr2->next=ptr;
                ptr->next-NULL;
            }
        }
        return head;
}

struct student *create_stu()
{
    struct student *head,*p;
    int num;
    float score;
    double grade;
    int size = sizeof(struct student);
    head = NULL;

    while(num!=-1){
        p=(struct student *)malloc(size);
        head = insert(head,p);
        scanf("%d %f %lf",&p->num,&p->score,&p->grade);
    }
    return head;
}

void print(struct student *head)
{
    struct student *p;
    p=head;
    if(head!=NULL){
        do{
        printf("%lf\n",p->grade);
        p=p->next;
    }while(p!=NULL);
    }
}

void require(struct student *head)
{
    struct student *p;
    long x;
    if(head!=NULL){
        p=head;
        while(p!=NULL){
            if(p->grade<60){
                printf("%7d%6.1f\n",p->num,p->score);;
                x++;
            }
            p=p->next;
        }
        printf("%ld\n",x);
    }
}
    int main(){
        struct student *head,*p;
        int num;
        float score;
        double grade;
        head = create_stu();
        print(head);
        require(head);
    }

*/
//结构example(未完成）
                /*
#include<stdio.h>
#include<string.h>
#define MaxSize 20
struct guest_info
{
	char name[8];
	int sum;
	char time[10];
	int number;
	struct guest_info *next;
}GuestLink,*Pointer;
void Insert(Pointer *Head);
void Search(Pointer Head);
void Update(Pointer Head);
void Delete(Pointer *Head);
void Show(Pointer Head);
int main()
{
	int i;
	Pointer Head=NULL;
	do
	{
	printf("\n");
	printf("1---插入(Insert)\n");
	printf("2---查询(Search)\n");
	printf("3---修改(Update)\n");
	printf("4---删除(Delete)\n");
	printf("5---显示(Show)\n");
	printf("6---退出(Exit)\n");
	scanf("%d",&i);
	switch(i)
	{
	case 1:Insert(&Head);
	break;
	case 2:Search(Head);
	break;
	case 3:Update(Head);
	break;
	case 4:Delete(&Head);
	break;
	case 5:Show(Head);
	break;
	case 6:break;
	dafault:printf("错误选择!请重选");
	break;
	}
	}
	while(i!=6);
	return 0;
}

void Insert(Pointer *Head)
{
	int in_number;
	Pointer p,q,r;
	printf("请输入编号:");
	scanf("%d",&in_number);
	p=q=*Head;
	while(p!=NULL){
		if(p->number==in_number){
			printf("已经有相同的编号:");
		}
		else{
			q=p;p=p->next;
		}
	}

    r=(Pointer)malloc(sizeof(GuestLink));
    r->next=NULL;
    if(r==NULL){
    	printf("分配空间失败！");
    	return;
    }

    if(q==NULL){
    	*Head=r;
    }
    else{
    	q->next=r;
    }
	r->number=in_number;
	printf("请输入姓名:");
	scanf("%s",r->name);
	printf("请输入人数:");
	scanf("%d",r->sum);
	printf("请输入用餐时间:");
	scanf("%s",r>time);
}

void Search(Pointer Head)
{
	int number,flag=1;
	Pointer p;
	printf("请输入要查询的编号:");
	scanf("%d",&number);
	p=Head;
	while(p!=NULL&&flag){
		if(p->number==number)
		{
			printf("姓名:%s",p->name);
			printf("人数:%d",p->.sum);
			printf("用餐时间:%s",p->.time);
			flag=0;
		}
	     else
			p=p->next;
	}
	if(flag)
 	    printf("没有查询到!!");
}

void Update(Pointer Head)
{
    int number,flag=1;
	Pointer p;
	printf("请输入要修改的编号:");
	scanf("%d",&number);
	p=Head;
	while(p!=NULL&&flag){
		if(p->number==number)
		{
 			printf("请输入人数：");
			scanf("%d",p->sum);
			printf("请输入用餐时间：");
			scanf("%s",p->time);
		    flag=0;
		}
		else
			p=p->next;
    }
	if(flag)
 		printf("没有找到要修改的记录!!");
}

void Show (Pointer Head)
{
   Pointer p;
   p=head;
   while(p!==NULL){
   	printf("姓名：%-10s",p->name);
   	printf("人数：%-10d",p->sum);
   	printf("用餐时间：%-10s",p->time);
   	printf("编号：%-10d\n",p->number);
   	p=p->next;
   }
}
*/
//不带表头结点的单向链表
/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <locale.h>
struct NODE {
    int          grade;
    struct NODE *next;
} *head,*p,*q,*s,*p1,*p2,*q1,**ta;
int i,k,n,t,m,v,N=10;
int main() {
    setlocale(LC_ALL,"chs");
    srand(time(NULL));

    head=NULL;

    printf("创建%d个节点的单链表:\n",N);//创建N个节点的单链表
    p=head;
    for (i=0;i<N;i++) {
        q=(struct NODE *)malloc(sizeof(struct NODE));
        if (NULL==q) exit(1);
        q->grade=rand()%100;//填写0..99的随机值
        q->next=NULL;
        if (NULL==p) {
            head=q;
            p=head;
        } else {
            p->next=q;
            p=q;
        }
    }

    //输出整个单链表
    s=head;
    while (1) {
        if (NULL==s) {
            printf("\n");
            break;
        }
        printf("%02d->",s->grade);
        s=s->next;
    }



    k=5;
    printf("删除第%d个节点:\n",k);//删除第k个节点
    n=0;
    p=head;
    while (1) {
        if (NULL==p) {
            break;
        }
        n++;
        if (k==1) {
            q=head;
            head=head->next;
            free(q);
            break;
        } else {
            if (k-1==n) {
                q=p->next;
                if (q) {
                    p->next=q->next;
                    free(q);
                }
                break;
            }
        }
        p=p->next;
    }

    //输出整个单链表
    s=head;
    while (1) {
        if (NULL==s) {
            printf("\n");
            break;
        }
        printf("%02d->",s->grade);
        s=s->next;
    }


    printf("将整个链表逆序:\n");//将整个链表逆序
    if (n>=2) {
        p=head;
        q=p->next;
        p->next=NULL;
        while (1) {
            q1=q->next;
            q->next=p;
            p=q;
            q=q1;
            if (NULL==q) break;
        }
        head=p;
    }

    //输出整个单链表
    s=head;
    while (1) {
        if (NULL==s) {
            printf("\n");
            break;
        }
        printf("%02d->",s->grade);
        s=s->next;
    }



    //释放所有节点
    p=head;
    while (1) {
        if (NULL==p) {
            break;
        }
        q=p->next;
        free(p);
        p=q;
    }

    return 0;
}
*/
/*

#include <stdio.h>
#include <stdlib.h>

#define N 20

struct ListNode {
    int grade;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *getodd( struct ListNode **L );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->grade);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *L, *Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
    printlist(L);

    return 0;
}


struct ListNode *readlist(){
	int i=0,in,n,a[N];
	struct ListNode *h,*p,*q;

	scanf("%d", &in);
	while(in != -1){
		a[i]=in;
		i++;
		scanf("%d", &in);
	}
	n=i;

	h = (struct ListNode*)malloc(sizeof(struct ListNode));
	h->grade = a[0];
	h->next = NULL;
	p=q=h;

	i=1;
	while(i<n){
		q = (struct ListNode*)malloc(sizeof(struct ListNode));
		q->grade = a[i];
		q->next = NULL;
		p->next = q;
		p=q;
		i++;
	}
	p->next=NULL;

	return h;
}

struct ListNode *getodd( struct ListNode **L ){
	struct ListNode *oddhead,*p,*q,*head;
	int a[N],i=0,n;

	head = *L;

	//先确定head->grade 不是奇数
	while(head->grade%2==1){
		a[i++]=head->grade;
		p = head->next;
		free(head);
		head = p;
	}

	q=head;
	p=head->next;
	while(p){
		if(p->grade%2==1){
			a[i++]=p->grade;
			q->next=p->next;
			free(p);
			p=q->next;

		}else{
            q=p;
            p=p->next;
        }
	}
	*L=head;

	n=i;
	oddhead = (struct ListNode*)malloc(sizeof(struct ListNode));
	oddhead->grade = a[0];
	oddhead->next = NULL;
	p=q=oddhead;

	i=1;
	while(i<n){
		q = (struct ListNode*)malloc(sizeof(struct ListNode));
		q->grade = a[i];
		q->next = NULL;
		p->next = q;
		p=q;
		i++;
	}
	p->next=NULL;

	return oddhead;
}
*/

//链表上级

//（1）单向链表建立：输入若干个学生信息（包括学号、姓名和成绩），输入学号为 0
//时输入结束，建立一个单向链表，再输入一个成绩值，将成绩大于等于该值的学生信息输出。
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct {
     int    num;
     char  name[20];
     int    score;
     struct  *next;
};

int main()
{
struct  *head,*tail, *p;
int num, score,i=1;
char name[20];
int size = sizeof(struct );
head=tail=NULL;
printf("请输入第%d个学生的学号",i);
scanf("%d", &num);
  while(num != 0){
printf("请输入第%d个学生的姓名和成绩",i++);
scanf("%s%d",name,&score);
p=(struct *)malloc(size);
p->num=num;
strcpy(p->name,name);
p->score=score;
p->next=NULL;
if(head==NULL)
head=p;
else
tail->next=p;
tail=p;
printf("请输入第%d个学生的学号",i);
scanf("%d",&num);
}
int t;
printf("请输入标准成绩:");
scanf("%d",&t);
for(p=head; p!=NULL; p=p->next)
    if(p->score>=t)
printf("%d %s %d\n", p->num,p->name,p->score);
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
struct numlinklist
{
int grade;
struct numlinklist *next;
};
int main()
{
    int temp;
    int size = sizeof(struct numlinklist);
    numlinklist * head,*tail,*tempP,*frontP,*deleteP;
    head=tail=NULL;

scanf("%d",&temp);
while(-1!=temp)
{
        if(head==NULL)
        {
        tail=head=(struct numlinklist*)malloc(size);
        head->grade=temp;
        head->next=NULL;
        }
        else
        {
        tempP=(struct numlinklist*)malloc(size);
        tempP->grade=temp;
        tempP->next=NULL;
        tail->next=tempP;
        tail=tempP;
        }
        scanf("%d",&temp);
}

tempP=head;
while(tempP!=NULL)
{
    if(tempP->grade%2==0)
    {
        if(tempP==head)
        {
        head=tempP->next;
        }
        else
        {

            for(frontP=head;frontP!=NULL;++frontP)
            {
                if(frontP->next==tempP)
                {
                frontP->next=tempP->next;
                break;
                }
            }
        }
}
    deleteP=tempP;
    tempP=tempP->next;
    if(0==deleteP->grade%2)
    free(deleteP);
}
tempP=head;
while(NULL!=tempP)
{
    printf("%d  ",tempP->grade);
    deleteP=tempP;
    tempP=tempP->next;
    delete deleteP;
}
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct NODE {
    char num[10];
    char name[10];
    double  grade;
    struct NODE *next;
} *head,*p,*q,*s;
int i,k,n,t,m,v;
char num[10],name[10];
double grade;
int main() {
    head=NULL;
    printf("创建单链表\n");//创建N个节点的单链表
    p=head;
    scanf("%s",num);
    scanf("%s",name);
    scanf("%lf",&grade);
    while(strcmp(num,"0")!=0) {

        q=(struct NODE *)malloc(sizeof(struct NODE));
        if (NULL==q) exit(1);
        strcpy(p->num,num);
        strcpy(p->name,name);
        p->grade=grade;
        q->next=NULL;
        if (NULL==p) {
            head=q;
            p=head;
        } else {
            p->next=q;
            p=q;
        }
        scanf("%s",num);
        scanf("%s",name);
        scanf("%lf",&grade);
    }
    //输出整个单链表
    s=head;
    while (1) {
        if (NULL==s) {
            printf("\n");
            break;
        }
        printf("学号：%s  姓名：%s  成绩：%lf",s->num,s->name,s->grade);

        s=s->next;
    }

    p=head;
    while (1) {
        if (NULL==p) {
            break;
        }
        q=p->next;
        free(p);
        p=q;
    }

    return 0;
}
*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct nodeStu{
    int num;
    char name[20];
    int score;
    struct nodeStu *next;
};
struct nodeStu *creatStu();
struct nodeStu *delStu(struct nodeStu *head,int min_score);
void print(struct nodeStu *head);
int main()
{
    struct nodeStu *head;
    int min_score;
    head=creatStu();
    printf("请输入标准分：\n");
    scanf("%d",&min_score);
    head=delStu(head,min_score);
    print(head);
}
struct nodeStu *creatStu()
{
    struct nodeStu *head,*tail, *p;
    int num, score;
    char name[20];
    int size = sizeof(struct nodeStu);
    head=tail=NULL;
    scanf("%d",&num);
    while(num != 0){
        scanf("%s%d",name,&score);
        p=(struct nodeStu*)malloc(size);
        p->num=num;
        strcpy(p->name,name);
        p->score=score;
        p->next=NULL;
        if(head==NULL)
        head=p;
        else
        tail->next=p;
        tail=p;
        scanf("%d",&num);
}
    return head;
}
struct nodeStu *delStu(struct nodeStu *head,int min_score)
{
    struct nodeStu*ptr1,*ptr2;
    while(head!=NULL&&head->score<min_score){
    ptr2=head;
    head=head->next;
    free(ptr2);
}
    if(head==NULL)
    return NULL;
    ptr1=head;
    ptr2=head->next;
    while(ptr2!=NULL){
    if(ptr2->score<min_score){
    ptr1->next=ptr2->next;
    free(ptr2);
}
    else
    ptr1=ptr2;
    ptr2=ptr1->next;
}
    return head;
}
void print(struct nodeStu *head)
{
    struct nodeStu*ptr;
    if(head==NULL){
    printf("\nNo Records\n");
}
    for(ptr=head; ptr; ptr=ptr->next)
    printf("%07d %s %d\n", ptr->num,ptr->name,ptr->score);
}
*/
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
} Node;
typedef struct Node *LinkList;
void CreateListHead(LinkList *L);
void PrintList(LinkList *L);
int main(int argc, char *argv[]) {
	LinkList list1;
	CreateListHead(&list1);
	PrintList(&list1);
	return 0;
}


void CreateListHead(LinkList *L)
{
	LinkList p;
	int number;
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;
	do
	{
		scanf("%d",&number);
		if(number!=-1)
		{
			p=(LinkList)malloc(sizeof(Node));
			p->data=number;
			p->next=(*L)->next;
			(*L)->next=p;
		}
	}while(number!=-1);
}

void PrintList(LinkList *L)
{
	LinkList p;
	for(p=(*L)->next;p->next!=NULL;p=p->next)	{
		printf("%d ",p->data);
	}
	printf("%d\n",p->data);
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} LinkList;

int main()
{
    LinkList * header = NULL;
    Node * p;
while (true)
{
    int t;
    int i = 0;
    scanf("%d", &t);
    if (t == -1) break;
    if (!header)
    {
        header = (LinkList *)malloc(sizeof(LinkList));
        p = header;
        header->data = t;
        header->next = NULL;
    }
        else
    {
        p->next = (Node *)malloc(sizeof(Node));
        p = p->next;
        p->data = t;
        p->next = NULL;
    }
}
    p = header;
    Node * pre = NULL;
    while (p)
    {
    if (p->data % 2 == 0)
    {
        Node * temp;
        if (!pre)
        {
            temp = header;
            header = header->next;
            p = header;
            free(temp);
        }
        else
        {
            temp = p;
            p = p->next;
            pre->next = p;
            free(temp);
            }
        }
        pre = p;
        p = p->next;
    }
    p = header;

    while (p)
    {
    printf("%d ", p->data);
    p = p->next;
    }
    printf("\n");
}
*/


#include<Stdio.h>
#include<string.h>
int main(){
    char c[]="Jones";
    printf("%d",strlen(c));
   printf("%d",sizeof(c));
}
