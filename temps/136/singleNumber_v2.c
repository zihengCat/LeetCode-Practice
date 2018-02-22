#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize);

int main(void){
    int array[] = {1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6};
    printf("%d\n",
            singleNumber(array, sizeof(array) / sizeof(array[0])));
    return 0;
}
int singleNumber(int* nums, int numsSize){
    int i;
    int ret;
    for(i = 0; i<numsSize; i++){
        ret ^= nums[i];
    }
    return ret;
}
