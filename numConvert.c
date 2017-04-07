#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define itoc(n)  ((n) + '0')

int  numConvert(int num, char *s, int base);
     void strReverse(char* s, int n);
void showStr(char* s);

int main(int argc, char* argv[]){

    int num = 0;
    scanf("%d", &num);
    char s[512];
    int n = numConvert(num, s, 2);
    showStr(s);

    return 0;
}

int numConvert(int num, char *s, int base){
    char *p = s;
    int i = 0;
    for(i = 0; num != 0; i++){
        *p = itoc(num % base);
        p++;

        num /= base;
    }
    *p = '\0';

    strReverse(s, i);
    return i;
}
void strReverse(char* s, int n){
    int first = 0;
    int last  = n - 1;
    for(first, last; first <= last; first++, last--){
        char tmp = s[first];
        s[first]  = s[last];
        s[last] = tmp;
    }
}
void showStr(char* s){
    while(*s){
        putc(*s, stdout);
        s++;
    }
    putc('\n', stdout);
}

