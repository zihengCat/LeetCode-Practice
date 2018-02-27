#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string convertToBase7(int num);

int main(void) {
    cout << convertToBase7(-100);
    return 0;
}

string convertToBase7(int num) {
    string ret;
    int flag = 0;
    if(num < 0) {
        num *= -1;
        flag = 1;
    }
    int remainder = 0;
    while(num) {
        remainder = num % 7;
        num /= 7;
        ret += to_string(remainder);
    }
    reverse(ret.begin(), ret.end());
    return flag == 0 ? ret : "-" + ret;
}

