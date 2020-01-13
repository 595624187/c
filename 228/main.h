int f(int a)
{
    int i,flag=1;
    if((a==1)||(a==0)) {
        flag=0;
    }else
    {
        for(i=2;i<a;i++){
            if(a%i==0) flag = 0;
        }
    }
    return flag;
}
