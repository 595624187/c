int is1[maxx],is2[maxx];// is1Ϊԭ���飬is2Ϊ��ʱ���飬nΪ���˶���ĳ���
long long Merge(int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    long long count=0;
    while(i<=mid&&j<=high)
        if(is1[i]<=is1[j])// �˴�Ϊ�ȶ�����Ĺؼ���������С��
            is2[k++]=is1[i++];
        else
        {
            is2[k++]=is1[j++];
            count+=j-k;// ÿ����ε�����Ԫ����ǰʱ����¼��ǰ�ľ���
        }
    while(i<=mid)
        is2[k++]=is1[i++];
    while(j<=high)
        is2[k++]=is1[j++];
    for(i=low; i<=high; i++) // д��ԭ����
        is1[i]=is2[i];
    return count;
}
long mergeSort(int a,int b)// �±꣬��������int is[5]��ȫ������ĵ���ΪmergeSort(0,4)
{
    if(a<b)
    {
        int mid=(a+b)/2;
        long count=0;
        count+=mergeSort(a,mid);
        count+=mergeSort(mid+1,b);
        count+=Merge(a,mid,b);
        return count;
    }
    return 0;
}
