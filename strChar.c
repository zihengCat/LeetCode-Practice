#include <stdio.h>
extern char* myStrch(char* s, char c);
int main(int argc, char* argv[]){
    char *s = "hello";
    char  c = 'l';

    printf("%s\n", myStrch(s, c));

    return 0;
}
char* myStrch(char* s, char c){
    while(*s){
        if(*s == c){
            return s;
        }
        s++;
    }
    return NULL;
}
