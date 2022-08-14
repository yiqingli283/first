#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
//自底向上的归并排序

void MergeArr(int* a, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int left = begin1, right = end2;
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	while (begin1 <= end1)
		tmp[index++] = a[begin1++];

	while (begin2 <= end2)
		tmp[index++] = a[begin2++];

	// 把归并好的再tmp的数据在拷贝回到原数组
	for (int i = left; i <= right; ++i)
		a[i] = tmp[i];
}


// 归并排序非递归实现
void MergeSort_BU(int* a, int n)
{
	assert(a);
	int* tmp = malloc(sizeof(int) * n);
	int gap = 1; //每组元素个数
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			// [i,i+gap-1] [i+gap, i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			// 1、合并时只有第一组,第二组不存在，就不需要合并
			if (begin2 >= n)
				break;

			// 2、合并时第二组只有部分数据，需要修正end2边界
			if (end2 >= n)
				end2 = n - 1;

			MergeArr(a, begin1, end1, begin2, end2, tmp);
		}
		gap *= 2;
	}
	free(tmp);
}

int main()
{
    int test[] = {3,2,5,6,7};
    int n = (int)(sizeof(test)/sizeof(test[0]));
    //printf("%d\n", (int)(sizeof(test)/sizeof(test[0])));
    MergeSort_BU(test,n);
    int i;
    for(i = 0;i < sizeof(test)/sizeof(test[0]);i++)
        printf("%d ",test[i]);
    return 0;
}