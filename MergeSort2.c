#include <stdio.h>
#include<stdlib.h>
#define INF 0x3f
//插入排序优化归并排序

void INSERTION_SORT(int*Arry,int Head,int Tail)
{
    int N=Tail-Head+1;
    for(int j=Head+1;j<=Tail;j++)
    {
        int key=Arry[j];
        int i=j-1;
        while(i>=Head && Arry[i]>key)
        {
            Arry[i+1]=Arry[i];
            i--;
        }
        Arry[i+1]=key;
    }
}

void MERGE(int *Arry,int beg,int mid,int endd)
{
    int n1=mid-beg+1,n2=endd-mid;
    int *L=(int*)malloc(sizeof(int)*(n1+2));//分配大小为n1个int字节的连续内存
    int *R=(int*)malloc(sizeof(int)*(n2+2));
    int i=1,j=1;
    for(i=1;i<=n1;i++) L[i]=Arry[beg+i-1];
    for(j=1;j<=n2;j++) R[j]=Arry[mid+j];
    L[n1+1]=INF;R[n2+1]=INF;
    i=1,j=1;
    for(int k=beg;k<=endd;k++)
    {
        if(L[i]<=R[j]) Arry[k]=L[i++];
        else Arry[k]=R[j++];
    }
    free(L);free(R);
}

void MergeSort(int *Arry,int head,int tail)
{
    if(head<tail-17)
    {
        int midd=(head+tail)/2;
        MergeSort(Arry,head,midd);
        MergeSort(Arry,midd+1,tail);
        MERGE(Arry,head,midd,tail);
    }
    else INSERTION_SORT(Arry,head,tail);
}

int main()
{
    int test[] = {1,2,5,6,3,3,8};
    int n = (int)(sizeof(test)/sizeof(test[0]));
   
    
    printf("%d\n", (int)(sizeof(test)/sizeof(test[0])));
    MergeSort(test,1,n-1);
    int i;
    for(i = 0;i < sizeof(test)/sizeof(test[0]);i++)
        printf("%d ",test[i]);
    return 0;
}