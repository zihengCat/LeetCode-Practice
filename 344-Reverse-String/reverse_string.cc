#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};

int main(void) {
    Solution s = Solution();
    cout << s.reverseString("hello") << endl;

    return 0;
}

