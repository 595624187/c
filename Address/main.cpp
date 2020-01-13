#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct contact{
    char name[10];
    char tel[15];
    char bir[10];
}contact;
void update_file(contact con[],int num);
void newContact(contact con[],int *num);
void changeContact(contact con[],int num);
void delete_name(contact con[],int num,char name[]);
int search_tel(contact con[],int num,char tel[]);
int search_bir(contact con[],int num,char bir[]);
int search_name(contact con[],int num,char name[]);
void print(contact con[],int num);
int input(contact con[]);
void showmeun(void);
char path[20]="D:\\contact.txt";
void print(contact con[],int num);
int main()
{
    contact con[100];
    int num=input(con);
    int button;
    while(1)
    {
        showmeun();
        scanf("%d",&button);
        if(button==1)
        {
            printf("联系人列表\n");
            print(con,num);
        }
        else if(button==2)
        {
            changeContact(con,num);
        }
        else if(button==3)
        {
            newContact(con,&num);
        }
        else if(button==4)
        {
             printf("请输入要删除的联系人的姓名\n");
             char s[20];
             scanf("%s",s);
             delete_name(con,num,s);
             num--;
        }
        else if(button==5)
        {
            printf("1通过姓名查询\n2通过电话查询\n3通过生日查询\n");
            int bt;
            scanf("%d",&bt);
            char s[20];
            scanf("%s",s);
            if(bt==1)
            {
               int ans=search_name(con,num,s);
               if(ans==-1)
                  printf("没有该联系人");
               else
                printf("该联系人的信息为 姓名:%s  电话%s  生日%s\n\n",con[ans].name,con[ans].tel,con[ans].bir);

            }
            if(bt==2)
            {
               int ans=search_tel(con,num,s);
               if(ans==-1)
                  printf("没有该联系人\n");
               else
                printf("该联系人的信息为 姓名:%s  电话%s  生日%s\n\n",con[ans].name,con[ans].tel,con[ans].bir);

            }
            if(bt==3)
            {
               int ans=search_bir(con,num,s);
               if(ans==-1)
                  printf("没有该联系人\n");
               else
                printf("该联系人的信息为 姓名:%s  电话%s  生日%s\n\n",con[ans].name,con[ans].tel,con[ans].bir);

            }


        }
        else if(button==0)
        {
            update_file(con,num);
            return 0;
        }
    }

}

int input(contact con[])
{
    int i=0;
    FILE *fp;
    fp=fopen(path,"r");
    if(fp==NULL)
    {
        printf("file open error");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s%s%s",con[i].name,con[i].tel,con[i].bir);
        i++;
    }
    fclose(fp);
    return i;
}

void print(contact con[],int num)
{
    int i;
    for(i=0;i<num;i++)
        printf("%s %s %s\n",con[i].name,con[i].tel,con[i].bir);
}

void showmeun(void)
{
    printf("*********  通讯录管理系统  ***********\n");
    printf("********* 1 联系人列表     ***********\n");
    printf("********* 2 修改联系人信息 ***********\n");
    printf("********* 3 添加联系人     ***********\n");
    printf("********* 4 删除联系人     ***********\n");
    printf("********* 5 查询联系人     ***********\n");
    printf("********* 0 退出           ***********\n");
    printf("**************************************\n");
}

void delete_name(contact con[],int num,char name[])//返回值是当前通讯录的人数
{
    int res=search_name(con,num,name);
    if(res==-1)
        printf("没有此联系人\n");
    else
    {
        int j;
        for(j=res;j<num;j++)
        {
            strcpy(con[j].name,con[j+1].name);
            strcpy(con[j].tel,con[j+1].tel);
            strcpy(con[j].bir,con[j+1].bir);
        }
        printf("删除成功\n");

    }
}

int search_name(contact con[],int num,char name[])
{
         int i;
         for(i=0;i<num;i++)
         {
             if(strcmp(con[i].name,name)==0)
              return i;
         }
         return -1;
}
int search_tel(contact con[],int num,char tel[])
{
         int i;
         for(i=0;i<num;i++)
         {
             if(strcmp(con[i].tel,tel)==0)
              return i;
         }
         return -1;
}int search_bir(contact con[],int num,char bir[])
{
         int i;
         for(i=0;i<num;i++)
         {
             if(strcmp(con[i].bir,bir)==0)
              return i;
         }
         return -1;
}

void changeContact(contact con[],int num){
    printf("****修改联系人信息****\n");
    printf("请输入联系人的手机号或姓名\n");
    char tp[15];
    char n[10];
    char b[10];
    int i=0;
    scanf("%s",tp);
    while((strcmp(tp, con[i].tel)!=0&&i<num)&&(strcmp(tp,con[i].name)!=0&&i<num)){
        i++;
    }
    if(strcmp(tp, con[i].tel)!=0&&strcasecmp(tp,con[i].name)){//可能出现没有这个联系人的情况
        printf("未找到该联系人!\n");
    }else {
        printf("旧的姓名：%s 旧的手机号%s 旧的生日：%s\n",con[i].name,con[i].tel,con[i].bir);
        printf("请问需要修改哪种信息？\n1.姓名\t2.电话\t3.生日\n");
        int choice;
        scanf("%d",&choice);
        if (choice == 1) {
            printf("请输入新的姓名：\n");
            scanf("%s",n);
            strcpy(con[i].name, n);
            printf("新的姓名：%s 新的手机号%s 新的生日：%s\n",con[i].name,con[i].tel,con[i].bir);
            printf("修改成功！\n");
        }
        else if(choice == 2){
            printf("请输入新的电话：\n");
            scanf("%s",tp);
            strcpy(con[i].tel, tp);
            printf("新的姓名：%s 新的手机号%s 新的生日：%s\n",con[i].name,con[i].tel,con[i].bir);
            printf("修改成功！\n");
        }
        else if(choice == 3){
            printf("请输入新的生日：\n");
            scanf("%s",b);
            strcpy(con[i].bir, b);
            printf("新的姓名：%s 新的手机号%s 新的生日：%s\n",con[i].name,con[i].tel,con[i].bir);
            printf("修改成功！\n");
        }
    }

}
//添加


void newContact(contact con[],int *num){
    printf("****新增联系人****\n");
    int i=(*num);//num表示最后一位联系人，所以新增联系人在最后一位的上一位
    printf("请输入联系人的姓名:\n");
    scanf("%s",con[i].name);
    printf("请输入联系人的手机号：\n");
    scanf("%s",con[i].tel);
    printf("请输入联系人的生日：\n");
    scanf("%s",con[i].bir);
    (*num)++;//新增了一位联系人，所以最后一位加一
}
void update_file(contact con[],int num)
{
    FILE *fp;
    fp=fopen(path,"w");
    if(fp==NULL)
    {
        printf("file open error");
        exit(0);
    }
    int i;
    for(i=0;i<num;i++)
     fprintf(fp,"%s %s %s\n",con[i].name,con[i].tel,con[i].bir);
     fclose(fp);
}
