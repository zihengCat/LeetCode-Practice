/* Enter 2 numbers, output the max */
#include <stdio.h>
int main(void){
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("The max of %d and %d is %d\n", 
            num1, num2, (num1 > num2 ? num1 : num2));
    return 0;
}
