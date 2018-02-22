/* convert charactor to their ASCII number value */
#include <stdio.h>
int main(void){
    char c;
    printf("Enter a string end with \"#\": ");
    while((c = getchar()) != '#'){
        printf("%d ", c);
    }
    printf("\n");

    return 0;
}

