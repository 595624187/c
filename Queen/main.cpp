 #include<stdio.h>
 int x[10]={-1};
 int count = 0;
 int abs(int i){
    if(i<0) i=-i;
    return i;
 }
 bool  place(int i)   //考察皇后i放置在x[i]列是否发生冲突
 {
      for (int j=1; j<i; j++) //j=1～i-1是已放置了皇后的行
        if (x[i]==x[j]||abs(i-j)==abs(x[i]-x[j]))
            return false;  //冲突返回false
      return true;
 }

void display(int n)
{
    printf("第%2d个解：",++count);
   for(int i=1;i<=n;i++)
 	printf("(%d,%d)",i,x[i]);
   printf("\n");
}

void Queen(int n)
{
    int i=1;//第i个皇后
    x[i]=0;//第x[i]列
    while(i>0){
        x[i]++;
        while(x[i]<=n&&!place(i)){
            x[i]++;
        }
        if(x[i]<=n){
            if(i==n)
                display(n);
            else{
                x[++i]=0;
            }
        }
        else i--;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    Queen(n);
    return 0;
}
