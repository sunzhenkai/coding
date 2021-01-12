#include <iostream>
#include "utils.h"
#include "leetcode.h"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int ml = 0, ll = 0;
        int n = s.length();
        int r = 0, l = 0;
        for (int i = 0; i < s.length();) {
            r = l = i;
            while (r + 1 < n&& s[r] == s[r+1]) ++r;
            i = r + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l; ++r;
            }
            if (r - l - 1 > ll) {
                ml = l + 1;
                ll = r - l - 1;
            }
        }
        return s.substr(ml, ll);
    }
};

int main() {
    Solution s;
    string inp;
    while (cin >> inp) {
        cout << s.longestPalindrome(inp) << endl;
    }
    return 0;
}
