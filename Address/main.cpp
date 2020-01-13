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
            printf("��ϵ���б�\n");
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
             printf("������Ҫɾ������ϵ�˵�����\n");
             char s[20];
             scanf("%s",s);
             delete_name(con,num,s);
             num--;
        }
        else if(button==5)
        {
            printf("1ͨ��������ѯ\n2ͨ���绰��ѯ\n3ͨ�����ղ�ѯ\n");
            int bt;
            scanf("%d",&bt);
            char s[20];
            scanf("%s",s);
            if(bt==1)
            {
               int ans=search_name(con,num,s);
               if(ans==-1)
                  printf("û�и���ϵ��");
               else
                printf("����ϵ�˵���ϢΪ ����:%s  �绰%s  ����%s\n\n",con[ans].name,con[ans].tel,con[ans].bir);

            }
            if(bt==2)
            {
               int ans=search_tel(con,num,s);
               if(ans==-1)
                  printf("û�и���ϵ��\n");
               else
                printf("����ϵ�˵���ϢΪ ����:%s  �绰%s  ����%s\n\n",con[ans].name,con[ans].tel,con[ans].bir);

            }
            if(bt==3)
            {
               int ans=search_bir(con,num,s);
               if(ans==-1)
                  printf("û�и���ϵ��\n");
               else
                printf("����ϵ�˵���ϢΪ ����:%s  �绰%s  ����%s\n\n",con[ans].name,con[ans].tel,con[ans].bir);

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
    printf("*********  ͨѶ¼����ϵͳ  ***********\n");
    printf("********* 1 ��ϵ���б�     ***********\n");
    printf("********* 2 �޸���ϵ����Ϣ ***********\n");
    printf("********* 3 �����ϵ��     ***********\n");
    printf("********* 4 ɾ����ϵ��     ***********\n");
    printf("********* 5 ��ѯ��ϵ��     ***********\n");
    printf("********* 0 �˳�           ***********\n");
    printf("**************************************\n");
}

void delete_name(contact con[],int num,char name[])//����ֵ�ǵ�ǰͨѶ¼������
{
    int res=search_name(con,num,name);
    if(res==-1)
        printf("û�д���ϵ��\n");
    else
    {
        int j;
        for(j=res;j<num;j++)
        {
            strcpy(con[j].name,con[j+1].name);
            strcpy(con[j].tel,con[j+1].tel);
            strcpy(con[j].bir,con[j+1].bir);
        }
        printf("ɾ���ɹ�\n");

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
    printf("****�޸���ϵ����Ϣ****\n");
    printf("��������ϵ�˵��ֻ��Ż�����\n");
    char tp[15];
    char n[10];
    char b[10];
    int i=0;
    scanf("%s",tp);
    while((strcmp(tp, con[i].tel)!=0&&i<num)&&(strcmp(tp,con[i].name)!=0&&i<num)){
        i++;
    }
    if(strcmp(tp, con[i].tel)!=0&&strcasecmp(tp,con[i].name)){//���ܳ���û�������ϵ�˵����
        printf("δ�ҵ�����ϵ��!\n");
    }else {
        printf("�ɵ�������%s �ɵ��ֻ���%s �ɵ����գ�%s\n",con[i].name,con[i].tel,con[i].bir);
        printf("������Ҫ�޸�������Ϣ��\n1.����\t2.�绰\t3.����\n");
        int choice;
        scanf("%d",&choice);
        if (choice == 1) {
            printf("�������µ�������\n");
            scanf("%s",n);
            strcpy(con[i].name, n);
            printf("�µ�������%s �µ��ֻ���%s �µ����գ�%s\n",con[i].name,con[i].tel,con[i].bir);
            printf("�޸ĳɹ���\n");
        }
        else if(choice == 2){
            printf("�������µĵ绰��\n");
            scanf("%s",tp);
            strcpy(con[i].tel, tp);
            printf("�µ�������%s �µ��ֻ���%s �µ����գ�%s\n",con[i].name,con[i].tel,con[i].bir);
            printf("�޸ĳɹ���\n");
        }
        else if(choice == 3){
            printf("�������µ����գ�\n");
            scanf("%s",b);
            strcpy(con[i].bir, b);
            printf("�µ�������%s �µ��ֻ���%s �µ����գ�%s\n",con[i].name,con[i].tel,con[i].bir);
            printf("�޸ĳɹ���\n");
        }
    }

}
//���


void newContact(contact con[],int *num){
    printf("****������ϵ��****\n");
    int i=(*num);//num��ʾ���һλ��ϵ�ˣ�����������ϵ�������һλ����һλ
    printf("��������ϵ�˵�����:\n");
    scanf("%s",con[i].name);
    printf("��������ϵ�˵��ֻ��ţ�\n");
    scanf("%s",con[i].tel);
    printf("��������ϵ�˵����գ�\n");
    scanf("%s",con[i].bir);
    (*num)++;//������һλ��ϵ�ˣ��������һλ��һ
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
