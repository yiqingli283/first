#include <iostream>
using namespace std;
//数组中的逆序对数

int inversePairsCore( int *iarr , int begin , int mid , int end , int *copy )
{
    if( begin < end )
    {
        int front = inversePairsCore( iarr,begin,(begin+mid)/2,mid,copy );
        int rear = inversePairsCore( iarr,mid+1,(mid+1+end)/2,end,copy );
        int inverseNumbers = front + rear ;
        int i = mid , j = end , k = end;

        while( i >= begin && j >= mid + 1 )
        {
            if( iarr[i] > iarr[j] )
            {
                inverseNumbers += j - mid;
                copy[k--] = iarr[i--];
            }
            else
            {
                copy[k--] = iarr[j--];
            }
        }
        while( i >= begin )
        {
            copy[k--] = iarr[i--];
        }
        while( j >= mid + 1 )
        {
            copy[k--] = iarr[j--];
        }

        i = begin , j = end;
        while( i <= j )
        {
            iarr[i] = copy[i];
            i++;
        }
        return inverseNumbers;
    }
    return 0;
}

//数组中的逆序对数
int inversePairs( int *iarr , int length )
{
    int *copy = new int[length];
    int counts = inversePairsCore( iarr , 0 , ( length - 1 )/2 , length - 1 , copy );
    delete [] copy;
    return counts;
}

int main()
{
    int iarr[] = { 7 , 5 , 6 , 4 };
    cout<< "inversePairsCounts:\t" << inversePairs( iarr , 4 ) << endl;
    return 0;
}
