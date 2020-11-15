#include <iostream>
#include "utils.h"
#include "leetcode.h"

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int smb = x >=0 ? 1 : -1;
        int res = 0;
        x = abs(x);
        while (x > 0) {
            res = res * 10 +  x % 10;
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
