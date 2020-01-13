#include <iostream>
using namespace std;
#define N 10
int x[N]={-1};
int abs(int i){
    if(i<0) i=-i;
    return i;
}

int Place(int k)
{
    for(int i=0;i<k;i++)
        if(x[i]==x[k]||abs(i-k)==abs(x[i]-x[k]))
        return 1;
    return 0;
}

void Queen(int n)
{
    int k=0;
    while(k>=0){
        x[k]++;
        while(x[k]<n&&Place(k)==1)
            x[k]++;
        if(x[k]<n&&k==n-1){
            for(int i=0;i<n;i++)
                cout<<x[i]+1<<" ";
            cout<<endl;
            return ;
        }
        if(x[k]<n&&k<n-1)
            k++;
        else
            x[k--]=-1;
    }
    cout<<"нч╫Б"<<endl;

}



int main()
{
    int n;
    cin>>n;
    while(n!=-1){
        Queen(n);
        for(int i=0;i<n;i++) x[i]=-1;
        cin>>n;
    }
    return 0;
}
