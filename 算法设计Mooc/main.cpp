/*
//数字旋转方针
#include<stdio.h>
int data[10][10];
void Full(int number,int begin,int size);
int main(){
    int i,j;
    Full(1,0,6);
    for(i=0;i<6;i++){
            for(j=0;j<6;j++){
                printf("%2d ",data[i][j]);
            }
            printf("\n");
    }
}
void Full(int number,int begin,int size){
int i,j,k;
if(size==0)
    return;
    if(size==1){
        data[begin][begin]=number;
        return;
    }
    i = begin;j=begin;
    for(k=0;k<size-1;k++){
        data[i][j]=number;
        number++;i++;
    }
    for(k=0;k<size-1;k++){
        data[i][j]=number;
        number++;j++;
    }
    for(k=0;k<size-1;k++){
        data[i][j]=number;
        number++;i--;
    }
    for(k=0;k<size-1;k++){
        data[i][j]=number;
        number++;j--;
    }
    Full(number,begin+1,size-2);
}
*/
/*
//归并排序
#include<stdio.h>
void Merge1(int r[],int r1[],int s,int m,int t){
    int i=s,j=m+1,k=s;
    while(i<=m&&j<=t)
        if(r[i]<=r[j]) r1[k++]=r[i++];
    else r1[k++]=r[j++];
    while(i<=m) r1[k++]=r[i++];
    while(j<=t) r1[k++]=r[j++];
}
void MergeSort1(int r[],int s,int t)
{
    int m,r1[1000];
    if(s==t) return;
    else{
        m=(s+t)/2;
        MergeSort1(r,s,m);
        MergeSort1(r,m+1,t);
        Merge1(r,r1,s,m,t);
        for(int i=s;i<=t;i++)
            r[i]=r1[i];
    }
}

int main()
{
    int a[]={8,3,2,6,7,1,5,4};
    MergeSort1(a,0,8);
    for(int i=0;i<8;i++)
        printf("%d",a[i]);
}
*/

//快速排序
#include<stdio.h>
int Partition(int r[],int first,int end)
{
    int i=first,j=end;
    while(i<j){
        while(i<j&&r[i]<=r[j])j--;
        if(i<j){
            int temp=r[i];r[i]=r[j];r[j]=temp;
            i++;
        }
        while(i<j&&r[i]<=r[j])i++;
        if(i<j){
            int temp=r[i];r[i]=r[j];r[j]=temp;
            j--;
        }
    }
    return i;
}
void QuickSort(int r[],int first,int end)
{
    int pivot;
    if(first<end){
        pivot=Partition(r,first,end);
        QuickSort(r,first,pivot-1);
        QuickSort(r,pivot+1,end);
    }
}
int main()
{
    int a[]={23,13,35,6,19,50,28};
    QuickSort(a,0,7);
    for(int i=0;i<7;i++) printf("%d ",a[i]);
}









