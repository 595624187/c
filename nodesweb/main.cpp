#include <stdio.h>
#include <stdlib.h>
#define INFINITY 10000 //定义权值的最大值
#define MAX_NUM 20 //图的最大顶点数
enum BOOL {False,True};
typedef struct
{
    int arcs[MAX_NUM][MAX_NUM]; //邻接矩阵
    int vexnum,arcnum; //图的当前顶点和边数
}Graph;
void CreateGraph(Graph &); //生成图的邻接矩阵
void ShortestPath_Floyd(Graph,BOOL[][MAX_NUM][MAX_NUM],int[][MAX_NUM]);
//用弗洛依德算法求每对顶点之间的最短路径

int main()
{
    Graph G; //采用邻接矩阵结构的图
    int u,i;
    BOOL P[MAX_NUM][MAX_NUM][MAX_NUM]; //存放每对顶点的最短路径
    int D[MAX_NUM][MAX_NUM]; //存放每对顶点的最短路径的距离

    CreateGraph(G); //生成邻接矩阵结构的图
    ShortestPath_Floyd(G,P,D); //利用弗洛依德算法求最短路径
}

void CreateGraph(Graph &G)
{
//构造邻接矩阵结构的图G
int i,j,k;
int start,end,weight;
do{
    printf("请输入村庄数目（2-19）和道路数目:\n");
    scanf("%d,%d",&G.vexnum,&G.arcnum); //输入图的顶点数和边数
    k=G.vexnum*(G.vexnum-1);
    if(G.arcnum>k)
    printf("error!!\n");
}while(G.arcnum<1||G.arcnum>k);
for(i=1;i<=G.vexnum;i++)
    for(j=1;j<=G.vexnum;j++)
        G.arcs[i][j]=INFINITY; //初始化邻接矩阵
        printf("请输入道路的起点和终点(i,j)及其路程：\n");
for(i=1;i<=G.arcnum;i++)
{
    scanf("%d,%d,%d",&start,&end,&weight); //输入边的起点和终点及权值
    G.arcs[start][end]=weight;
}
}


void ShortestPath_Floyd(Graph G,BOOL P[][MAX_NUM][MAX_NUM],int D[][MAX_NUM])
{
//用弗洛依德算法求有向网G的每对顶点v和w之间的最短路径P[v][w]
//及其带权路径长度D[v][w],
//若P[v][w][u]为True,表明u是从v到w当前求得最短路径上的顶点
int u,v,w,i,j,k,x;
int a[21]; //最短路径求和数组
for(v=1;v<=G.vexnum;v++) //各对顶点之间的初始已知路径及距离
    for(w=1;w<=G.vexnum;w++)
    {D[v][w]=G.arcs[v][w];
        for(u=1;u<=G.vexnum;u++) P[v][w][u]=False;
            if(D[v][w]<INFINITY) //从v到w有直接路径
            {P[v][w][v]=True;P[v][w][w]=True;}
}
{ for(u=1;u<=G.vexnum;u++)
    for(v=1;v<=G.vexnum;v++)
        for(w=1;w<=G.vexnum;w++)
            if(D[v][u]+D[u][w]<D[v][w]&&v!=w) //从v经u到w的一条路径更短
            {D[v][w]=D[v][u]+D[u][w];
                for(i=1;i<=G.vexnum;i++)
                if(P[v][u][i]||P[u][w][i]) P[v][w][i]=True;
}
}
printf("生成的最短路径的邻接矩阵为：\n");
for(v=1;v<=G.vexnum;v++)
    {
    for(w=1;w<=G.vexnum;w++)
    printf("%7d", D[v][w]);
    printf("\n");
    }

printf("最短路径求和数组为：");
for(w=1;w<=G.vexnum;w++)
{
    j=0;
    for(v=1;v<=G.vexnum;v++)
    j=j+D[v][w];
     //顶点到其它顶点最短距离的距离之和
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
printf("最适合建医院的村庄为：%d\n",k);
}
