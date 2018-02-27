#include <stdio.h>
#include <stdlib.h>
#define to_char(n) \
        (n + '0')

char* convertToBase7(int num);
char* str_reverse(char* s);

int main(void) {
    printf("%d: %d", 1, '1');
    printf("%d: %s\n", 200, str_reverse(convertToBase7(200)));
    return 0;
}

char* convertToBase7(int num) {
    char* s = (char*)malloc(sizeof(char)*32);
    char* new_s = NULL;
    if(num < 0) {
        num *= -1;
        s[0] = '-',
        new_s = s + 1;
    }
    else {
        new_s = s + 0;
    }

    int i = 0;
    int base = 7;
    int ret = 0;
    int quotient = num;
    int remainder = 0;
    while(num) {
        remainder = num % base;
        quotient  = num / base;
        num = quotient;
        new_s[i++] = to_char(remainder);
    }
    new_s[i] = '\0';
    return s;
}

char* str_reverse(char* s){
    char* p_begin = s;
    char* p_end   = s;
    while(*p_end != '\0'){
        p_end++;
    }
    p_end--;
    while(p_begin != p_end) {
        char tmp = *p_begin;
        *p_begin = *p_end;
        *p_end = tmp;
        p_begin++, p_end--;
    }
    return s;
}

/*
char to_char(int n){
    switch(n) {
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
        case 0: return '0';
        default: return -1;
    }
}
*/
