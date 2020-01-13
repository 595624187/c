#include <stdio.h>
#include <stdlib.h>
#define INFINITY 10000 //����Ȩֵ�����ֵ
#define MAX_NUM 20 //ͼ����󶥵���
enum BOOL {False,True};
typedef struct
{
    int arcs[MAX_NUM][MAX_NUM]; //�ڽӾ���
    int vexnum,arcnum; //ͼ�ĵ�ǰ����ͱ���
}Graph;
void CreateGraph(Graph &); //����ͼ���ڽӾ���
void ShortestPath_Floyd(Graph,BOOL[][MAX_NUM][MAX_NUM],int[][MAX_NUM]);
//�ø��������㷨��ÿ�Զ���֮������·��

int main()
{
    Graph G; //�����ڽӾ���ṹ��ͼ
    int u,i;
    BOOL P[MAX_NUM][MAX_NUM][MAX_NUM]; //���ÿ�Զ�������·��
    int D[MAX_NUM][MAX_NUM]; //���ÿ�Զ�������·���ľ���

    CreateGraph(G); //�����ڽӾ���ṹ��ͼ
    ShortestPath_Floyd(G,P,D); //���ø��������㷨�����·��
}

void CreateGraph(Graph &G)
{
//�����ڽӾ���ṹ��ͼG
int i,j,k;
int start,end,weight;
do{
    printf("�������ׯ��Ŀ��2-19���͵�·��Ŀ:\n");
    scanf("%d,%d",&G.vexnum,&G.arcnum); //����ͼ�Ķ������ͱ���
    k=G.vexnum*(G.vexnum-1);
    if(G.arcnum>k)
    printf("error!!\n");
}while(G.arcnum<1||G.arcnum>k);
for(i=1;i<=G.vexnum;i++)
    for(j=1;j<=G.vexnum;j++)
        G.arcs[i][j]=INFINITY; //��ʼ���ڽӾ���
        printf("�������·�������յ�(i,j)����·�̣�\n");
for(i=1;i<=G.arcnum;i++)
{
    scanf("%d,%d,%d",&start,&end,&weight); //����ߵ������յ㼰Ȩֵ
    G.arcs[start][end]=weight;
}
}


void ShortestPath_Floyd(Graph G,BOOL P[][MAX_NUM][MAX_NUM],int D[][MAX_NUM])
{
//�ø��������㷨��������G��ÿ�Զ���v��w֮������·��P[v][w]
//�����Ȩ·������D[v][w],
//��P[v][w][u]ΪTrue,����u�Ǵ�v��w��ǰ������·���ϵĶ���
int u,v,w,i,j,k,x;
int a[21]; //���·���������
for(v=1;v<=G.vexnum;v++) //���Զ���֮��ĳ�ʼ��֪·��������
    for(w=1;w<=G.vexnum;w++)
    {D[v][w]=G.arcs[v][w];
        for(u=1;u<=G.vexnum;u++) P[v][w][u]=False;
            if(D[v][w]<INFINITY) //��v��w��ֱ��·��
            {P[v][w][v]=True;P[v][w][w]=True;}
}
{ for(u=1;u<=G.vexnum;u++)
    for(v=1;v<=G.vexnum;v++)
        for(w=1;w<=G.vexnum;w++)
            if(D[v][u]+D[u][w]<D[v][w]&&v!=w) //��v��u��w��һ��·������
            {D[v][w]=D[v][u]+D[u][w];
                for(i=1;i<=G.vexnum;i++)
                if(P[v][u][i]||P[u][w][i]) P[v][w][i]=True;
}
}
printf("���ɵ����·�����ڽӾ���Ϊ��\n");
for(v=1;v<=G.vexnum;v++)
    {
    for(w=1;w<=G.vexnum;w++)
    printf("%7d", D[v][w]);
    printf("\n");
    }

printf("���·���������Ϊ��");
for(w=1;w<=G.vexnum;w++)
{
    j=0;
    for(v=1;v<=G.vexnum;v++)
    j=j+D[v][w];
     //���㵽����������̾���ľ���֮��
    a[w]=j;
    printf("%7d",a[w]);
}

printf("\n");
x=a[1];k=1;
for(w=1;w<=G.vexnum;w++)
{
    if(a[w]<x)
    {x=a[w];
    k=w;}
}
printf("���ʺϽ�ҽԺ�Ĵ�ׯΪ��%d\n",k);
}
