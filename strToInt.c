#include <stdio.h>
#include <assert.h>

#define ISDIGIT(n)         \
    ((n) >= '0' && (n) <= '9')

#define CTOI(n)            \
    ((n) - '0')

void myStoi(char* s, int* n, int base);

int main(int argc, char* argv[]){
    char s[] = "11111111";
    int n = 0;
    myStoi(s, &n, 2);
    printf("%d\n", n);
    return 0;
}
void myStoi(char* s, int* num, int base){
    *num = 0;
    while(*s){
        *num = *num * base + CTOI(*s);
        s++;
    }
}

