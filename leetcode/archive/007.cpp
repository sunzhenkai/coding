#include <iostream>
#include "utils.h"
#include "leetcode.h"

using namespace std;

class Solution {
    int INT_MAX_DEC = INT_MAX / 10;
    int INT_MIN_DEC = INT_MIN / 10;
    int INT_MAX_LAST = INT_MAX % 10;
    int INT_MIN_LAST = INT_MIN % 10;
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int pop = x % 10;
            if (res > INT_MAX_DEC || (INT_MAX_DEC == res && INT_MAX_LAST < pop))
                return 0;
            if (res < INT_MIN_DEC || (INT_MIN_DEC == res && INT_MIN_LAST < pop))
                return 0;
            res = res * 10 + pop;
            x /= 10;
        }
        return res;
    }
};

int main() {
    int x = r<int>();
    Solution s;
    cout << s.reverse(x) << endl;
    return 0;
}
