#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define N 200
int median(int a[], int n);
int getMedian(int a1[], int a2[], int n);
int main()
{
    FILE *fp,*fp1;
    if((fp=fopen("d:\\input1.txt","r"))==NULL){
        printf("File open error!\n");
            exit(0);
    }
    if((fp1=fopen("d:\\output1.txt","w"))==NULL){
        printf("File open error!\n");
            exit(0);
    }
    int n,i,j,a[N],b[N],mid=-1;

    while(!feof(fp)) printf("%c",fgetc(fp));
    fseek(fp,0L,SEEK_SET);
    if(!feof(fp)){
       fscanf(fp,"%d",&n);
    }
    for(i=0;i<n;i++) fscanf(fp,"%d",&a[i]);
    for(i=0;i<n;i++) fscanf(fp,"%d",&b[i]);
    mid = getMedian(a,b,n);
    printf("\nThe median is %d\n",mid);
    fprintf(fp1,"%d",mid);
    if(fclose(fp)){
        printf("Can not close !");
        exit(0);
    }
    if(fclose(fp1)){
        printf("Can not close !");
        exit(0);
    }
}
int median(int a[],int n)
{
    if(n%2==0)
        return (a[n/2]+a[n/2-1])/2;
    else
        return a[n/2];
}

int getMedian(int a1[], int a2[], int n)
{
    int m1,m2;
if (n <= 0)
    return -1;
if(n == 1)
    return (a1[0]+a2[0])/2;
if (n == 2)
    return(max(a1[0],a2[0]) + min(a1[1],a2[1]))/2;
    m1 = median(a1, n);
    m2 = median(a2, n);
if (m1 == m2)
    return m1;
if (m1 < m2)
{
    if (n % 2 == 0)
        return getMedian(a1+n/2-1,a2,n/2+1);
    else
        return getMedian(a1+n/2,a2,n/2+1);
}
    else
{
    if (n % 2 == 0)
        return getMedian(a2+n/2-1,a1,n/2+1);
    else
        return getMedian(a2+n/2,a1,n/2+1);
}
}






