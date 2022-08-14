#include <stdio.h>

void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, j=midIndex+1, k = startIndex;
    //首先将小的放在前面
    while(i!=midIndex+1 && j!=endIndex+1)
    {
        if(sourceArr[i] > sourceArr[j])//如果前半部分比后半部分大，就将小的放在前面
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1)
        tempArr[k++] = sourceArr[i++];//小的放在前面
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if(startIndex < endIndex)
    {
        midIndex = startIndex + (endIndex-startIndex) / 2;//避免溢出int
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}

int main()
{
    int test[] = {1,2,5,6,7,8,4,2,3,4,1,2,3};
    int n = (int)(sizeof(test)/sizeof(test[0]));
    int a[13];
    printf("%d\n", (int)(sizeof(test)/sizeof(test[0])));
    MergeSort(test,a,0,n - 1);
    int i;
    for(i = 0;i < sizeof(test)/sizeof(test[0]);i++)
        printf("%d ",test[i]);
    return 0;
}