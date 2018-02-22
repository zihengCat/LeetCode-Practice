#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE   32
#define STACK_INCRESEMENT 32

typedef char elemType;
typedef struct _sqstack__{
    elemType *base;
    elemType *top;
    int      stackSize;
}sqStack;

void initStack(sqStack *s);
void pushStack(sqStack *s, elemType *e);
void popStack (sqStack *s, elemType *e);
int  lenStack (const sqStack *s);

int  myPow (int base, int p);

int main(int argc, char* argv[]){

    elemType c;
    sqStack  s;
    int i, sum = 0, len;

    initStack(&s);

    while((c = getchar()) != '#'){
//      printf("%c %d\n", c, c);
        pushStack(&s, &c);
    }
    len = lenStack(&s);
    printf("%d\n", len);
    for(i = 0; i<len; i++){
        popStack(&s, &c);
//      printf("%c %d\n", c, c);
        sum = sum + (c-'0') * myPow(2, i);
    }
    printf("%d\n", sum);

    return 0;
}
void initStack(sqStack *s){
    if((s->base = (elemType*)malloc(STACK_INIT_SIZE * sizeof(elemType))) == NULL){
        exit(0);
    }
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
}
void pushStack(sqStack *s, elemType *e){
    if(s->top - s->base >= s->stackSize){
        if((s->base = (elemType*)realloc(s->base, 
        (s->stackSize + STACK_INCRESEMENT)*sizeof(elemType))) == NULL){
            exit(0);
        }
    }
    *(s->top) = *e;
    (s->top)++;
}
void popStack (sqStack *s, elemType *e){
    if(s->top == s->base){
        return;
    }
    (s->top)--;
    *e = *(s->top);
}
int  lenStack (const sqStack *s){
    return (int)(s->top - s->base);
}

int  myPow (int base, int p){
    int ret = 1;
    while(p){
        ret *= base;
        p--;
    }
    return ret;
}
