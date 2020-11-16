#include <iostream>
#include "utils.h"
#include "leetcode.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x > 0 && x % 10 == 0))
            return false;
        else if (x < 10)
            return true;

        int bot = 0;
        while (x / 10 > bot) {
            bot = bot * 10 + x % 10;
            x /= 10;
        }

        return bot == x || (x >= 10 & x / 10 == bot);
    }
};

int main() {
    int i = r<int>();
    Solution s;
    cout << s.isPalindrome(i) << endl;
    return 0;
}
