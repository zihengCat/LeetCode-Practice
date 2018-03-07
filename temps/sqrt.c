#include <stdio.h>

#define LIMIT 0.001

#define myAbs(n) \
    ((n) < 0 ? -(n) : (n))

#define myLimit(n, l) \
    ((n)*(n)-(l))

double mySqrtV1(double n);
double mySqrtV2(double n);

int main(void) {
    for(int i = 0; i<17; i++){
        // printf("mySqrtV1(%lf) = %lf\n", (double)i, mySqrtV1(((double)i)));
        printf("mySqrtV2(%lf) = %lf\n", (double)i, mySqrtV2(((double)i)));
    }
    return 0;
}

double mySqrtV1(double n) {
    double guess = n/2;
    double height = n, low = 0;
    do {
        if(myLimit(guess, n) > 0) {
            height = guess;
            guess = (low + height)/2;
        }
        else if(myLimit(guess, n) < 0) {
            low = guess;
            guess = (low + height)/2;
        }
        else {
            break;
        }

    } while(myAbs(myLimit(guess, n)) > LIMIT);
    return guess;
}

double mySqrtV2(double n) {
    if(n <= 0){ return 0; }
    double ret = n;
    double lst = 0;
    do {
        lst = ret;
        ret = (ret + n/ret)/2;
    } while(myAbs(ret - lst) > LIMIT);
    return ret;
}

