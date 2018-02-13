#include <stdio.h>

void printArrary(int* a, int size);
void quickSort(int *a, int low, int high);

void quickSort(int *a, int low, int high)
{
    /* 递归终止条件 */
    if(low >= high)
    {
        return;
    }
    /* 取出基准值 */
    int pivot = a[low];
    /* 设置左右游标 */
    int i = low + 1;
    int j = high;

    while(i <= j)
    {
        if(a[i] <= pivot)
        {
            i++;
        }
        else if(a[j] > pivot)
        {
            j--;
        }
        else
        {
            /* 交换 a[i], a[j] */
            a[i] = a[i] ^ a[j];
            a[j] = a[i] ^ a[j];
            a[i] = a[i] ^ a[j];
            i++;
            j--;
        }
    }

    /* 交换a[low], a[j] */
    a[low] = a[j];
    a[j] = pivot;
    j--;
    /* 递归左右两边 */
    quickSort(a, low, j);
    quickSort(a, i, high);
}

void printArrary(int* a, int size)
{
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(int argc, const char** argv)
{
    int array[]= {5, 9, 2, 7, 8, 3, 6, 1, 4, 0};
    int size = sizeof(array)/sizeof(int);
    printArrary(array, size);
    quickSort(array, 0, size - 1);
    printArrary(array, size);

    return 0;
}

