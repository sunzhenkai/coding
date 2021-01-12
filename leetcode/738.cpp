#include <iostream>
#include "utils.h"
#include "leetcode.h"

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if (N < 10) return N;
        int rem = 0, last = INT_MAX, mx = 1;
        while (N > 0) {
            int cur = N % 10;
            if (cur > last) {
                rem = mx - 1;
                cur -= 1;
            }

            rem += cur * mx;
            mx *= 10;
            N /= 10;
            last = cur;
        }
        return rem;
    }
};

int main() {
    Solution s;
    int n;
    while (cin >> n)
        cout << s.monotoneIncreasingDigits(n) << endl;
    return 0;
}
