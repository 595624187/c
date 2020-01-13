#include <cstdio>
#include <cstring>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
struct node
{
    char s1[10], s2[20] ;
} g[100];
/* ʾ��
3
S->pA|qB
A->cAd|a
B->dB|b
*/
char s[100] ;
int num ;
map<char,int> Map1;//���ս��ӳ��
map<char,int> Map2;//�Է��ս��ӳ��
int Map1_num, Map2_num;//��¼�ս�����������ս������
char s1[100] , s2[100] ;//�洢�ս���ͷ��ս��
int first[20][20] ;
int follow[20][20] ;
int vis[100];//��ֹ�ظ��ݹ�
int acc[20] ;//ʹ������õļ���
int select1[100][20] ;
int c[20][20] ;
char sta[100] ;
int cnt ;
void dfs1(char ch,int dis[])
{
    if( acc[ Map1[ch] ] )
    {
        for(int i = 1 ; i <= Map2_num; i++)
            dis[i] = first[ Map1[ch] ][i] ;
        return ;
    }
    int value[20] ;
    memset(value,0,sizeof(value));
    for(int i = 1 ; i <= num ; i++)
    {
        if( vis[i] ) continue ;
        if( g[i].s1[0] != ch ) continue ;
        int j , k , len = strlen(g[i].s2) ;
        for(j = 0 ; j < len ; j++)
        {
            if( Map1[ g[i].s2[j] ] )
            {
                vis[i] = 1 ;
                dfs1(g[i].s2[j],value);
                for(k = 2 ; k <= Map2_num ; k++)
                    if( value[k] ) dis[k] = 1 ;
                if( value[1] == 0 ) return ;
            }
            else
            {
                dis[ Map2[ g[i].s2[j] ] ] = 1 ;
                break;
            }
        }
        if( j == len )
            dis[1] = 1 ;
    }
    return ;
}
void dfs2(char ch,int dis[])
{
    int i , j , k , len , flag = 0 ;
    if( acc[ Map1[ch] ] )
    {
        for(int i = 1 ; i <= Map2_num; i++)
            dis[i] = follow[ Map1[ch] ][i] ;
        return ;
    }
    for(i = 1 ; i <= num ; i++)
    {
        len = strlen(g[i].s2) ;
        for(j = 0 ; j < len ; j++)
        {
            if( g[i].s2[j] == ch )
            {
                flag = 1 ;
                continue ;
            }
            if( !flag ) continue ;
            if( Map1[ g[i].s2[j] ] )
            {
                for(k = 2 ; k <= Map2_num ; k++)
                    if( first[ Map1[ g[i].s2[j] ] ][k] ) dis[k] = 1 ;
                if( !first[ Map1[ g[i].s2[j] ] ][1] )
                    flag = 0 ;
            }
            else
            {
                dis[ Map2[ g[i].s2[j] ] ] = 1 ;
                flag = 0 ;
            }
        }
        if( !flag || vis[i] ) continue ;
        int value[20] ;
        memset(value,0,sizeof(value));
        vis[i] = 1 ;
        dfs2(g[i].s1[0],value);
        for(i = 1 ; i <= Map2_num; i++)
            if( value[i] ) dis[i] = 1 ;

    }
}
int main()
{
    int i , j , k , len ;
    num = Map1_num = Map2_num = 0 ;
    Map1.clear();
    Map2.clear();
    Map2[ '@' ] = ++Map2_num;
    s2[ Map2_num ] = '@';
    int m;
    scanf("%d", &m);
    while( m-- )
    {
        scanf("%s", s);
        len = strlen(s) ;
        num++ ;
        for(i = 0 ; i < 1 ; i++)
        {
            g[num].s1[i] = s[i] ;
            if( !Map1[ s[i] ] )
            {
                Map1[ s[i] ] = ++Map1_num ;
                s1[Map1_num] = s[i];
            }
        }
        g[num].s1[i] = '\0' ;
        for(i = 3 ; i < len ; i++)
        {
            g[num].s2[i-3] = s[i] ;
            if( s[i] >= 'A' && s[i] <= 'Z' )
            {
                if( !Map1[ s[i] ] )
                {
                    Map1[ s[i] ] = ++Map1_num ;
                    s1[Map1_num] = s[i];
                }
            }
            else
            {
                if( !Map2[ s[i] ] )
                {
                    Map2[ s[i] ] = ++Map2_num;
                    s2[Map2_num] = s[i];
                }
            }
        }
        g[num].s2[i-3] = '\0';
    }
    //��first
    memset(first,0,sizeof(first));
    memset(acc,0,sizeof(acc));
    for(i = 1 ; i <= Map1_num ; i++)
    {
        int value[20];
        memset(vis,0,sizeof(vis));
        memset(value,0,sizeof(value));
        dfs1(s1[i],value);
        for(j = 1 ; j <= Map2_num; j++)
            first[i][j] = value[j] ;
        acc[i] = 1 ;
        printf("first[%c] = ", s1[i]);
        for(j = 1 ; j <= Map2_num ; j++)
        {
            if( first[i][j] )
                printf("%c ", s2[j]);
        }
        printf("\n");
    }
    //��follow
    Map2['#'] = ++Map2_num ;
    s2[ Map2_num ] = '#' ;
    memset(follow,0,sizeof(follow));
    memset(acc,0,sizeof(acc));
    for(i = 1 ; i <= Map1_num ; i++)
    {
        int value[20] ;
        memset(vis,0,sizeof(vis)) ;
        memset(value,0,sizeof(value));
        if( s1[i] == 'S' ) value[ Map2['#'] ] = 1 ;
        dfs2(s1[i],value);
        for(j = 1 ; j <= Map2_num; j++)
            follow[i][j] = value[j] ;
        acc[i] = 1 ;
        printf("follow[%c] = ", s1[i]);
        for(j = 1 ; j <= Map2_num ; j++)
        {
            if( follow[i][j] )
                printf("%c ", s2[j]);
        }
        printf("\n");
    }
    return 0;
}
