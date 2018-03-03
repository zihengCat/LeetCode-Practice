#include <stdio.h>

#define LIMIT 0.001

#define myAbs(n) \
    ((n) < 0 ? -(n) : (n))

#define myLimit(n, l) \
    ((n)*(n)-(l))

double mySqrt(double n);

int main(void) {
    for(int i = 0; i<17; i++){
        printf("mySqrt(%lf) = %lf\n", (double)i, mySqrt(((double)i)));
    }
    return 0;
}

double mySqrt(double n) {
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

