#include <iostream>
#include "utils.h"
#include "leetcode.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        if (x < 10) {
            return true;
        }

        int l = 10, r = 10;
        while (x / l >= 10) {
            l *= 10;
        }

        while (l >= r) {
            if (x / l % 10 != x % r / (r / 10)) {
                return false;
            }

            l /= 10;
            r *= 10;
        }

        return true;
    }
};

int main() {
    int i = r<int>();
    Solution s;
    cout << s.isPalindrome(i) << endl;
    return 0;
}
