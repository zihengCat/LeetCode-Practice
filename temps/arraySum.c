#include <stdio.h>
#include <stdlib.h>
#define N 128
#define ISDIGITS(x) \
    ((x) >= '0' && (x) <= '9')
#define ISSPACE(x)  \
    ((x) == ' ' || (x) == '\t' || (x) == '\n')

int process(char *s);

int main(void){

    printf("Please enter a series of number: ");
    char str[N];
    fgets(str, N, stdin);
    printf("%d\n", process(str));

    return 0;
}
int process(char *s){

    int sum = 0;
    char *p = s;

    while(*p != '\0'){
        if(ISSPACE(*p)){
            p++;
        }
        else if(ISDIGITS(*p)){

            size_t i = 0;
            char *pp = p;
            while(ISDIGITS(*pp)){
                i++;
                pp++;
            }
            int tmp;
            sscanf(p, "%d", &tmp);
            sum += tmp;
            p += i;
        }
        else{
        }
    }
    return sum;
}


