#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize);
void show_array(int* a, int size);

int main(void){
    int array[] = {1, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6};
   //  show_array(singleNumber(array, sizeof(array) / sizeof(array[0])),
   //                                (sizeof(array) / sizeof(array[0])) / 2 + 1
   //            );
   printf("%d\n",
         singleNumber(array, sizeof(array) / sizeof(array[0])));
    return 0;
}

void show_array(int* a, int size){
    int i;
    printf("[");
    for(i = 0; i < size; i++){
        printf("%d, ", a[i]);
    }
    printf("]\n");
}
int singleNumber(int* nums, int numsSize){
    int i, j;
    int count = 0;
    int flag;
    int* sets_array = (int*)malloc(sizeof(int)*(numsSize/2 + 1));
    for(i = 0; i < numsSize; i++){
        flag = 0;
        for(j = 0; j<i; j++){
            if(nums[i] == sets_array[j]){
                flag = 1;
            }
        }
        switch(flag){
            case 0:
                sets_array[count] = nums[i];
                count++;
                break;
            case 1:
                break;
        }
    }
    int sum_nums = 0, sum_sets = 0;
    for(i = 0; i < numsSize; i++){
        sum_nums += nums[i];
    }
    for(j = 0; j < numsSize/2 + 1; j++){
        sum_sets += sets_array[j];
    }
    free(sets_array);
    return sum_sets*2 - sum_nums;
}
