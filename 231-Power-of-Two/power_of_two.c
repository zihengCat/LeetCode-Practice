#include <stdio.h>

int isPowerOfTwo_v1(int n);
int isPowerOfTwo_v2(int n);

int main(void) {
    int i = 0;
    for(i = 0; i < 100; i++) {
        printf("%d: %s\n", i, isPowerOfTwo_v1(i) == 0 ? "false" : "true");
    }
    return 0;
}

int isPowerOfTwo_v1(int n) {
    if(n <= 0) {
        return 0;
    }
    int quotient = n,
        remainer = 0;
    while(quotient != 1) {
        remainer = quotient % 2;
        quotient /= 2;
        if(remainer) {
            return 0;
        }
    }
    return 1;
}

int isPowerOfTwo_v2(int n) {
    return n <= 0 ? 0 :  !(n & (n-1));
}

