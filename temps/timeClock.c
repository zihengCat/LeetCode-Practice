#include <stdio.h>
#include <time.h>
int main(void){
    time_t begin, end;
    begin = clock();
    int i;
    for(i = 0; i<1000000000; i++){
    }
    end = clock();
    printf("%.2f\n", (double)(end-begin));
    return 0;
}

