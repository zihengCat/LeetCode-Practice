#include <stdio.h>
extern int myStrlen(char* s);
int main(int argc, char* argv[]){
    char* s = "hello";
    printf("%d\n", myStrlen(s));

    return 0;
}

int myStrlen(char* s){
    char *p = s;
    while(*p){
        p++;
    }
    return ((int)(p - s));
}

