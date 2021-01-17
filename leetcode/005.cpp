/**
 * @file   005.cpp
 *
 * @brief  最长回文子串
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Sat Jan 16 13:40:48 CST 2021
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include "../template/utils.h"
#include "../template/leetcode.h"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size(), ri, i, j, c = 0, mxl = 0;
        while (c < len) {
            int i = c, j = c;
            while (j + 1 < len && s[j] == s[j+1]) { ++j; ++c; };
            while (i >= 0 && j < len && s[i] == s[j]) { --i; ++j; }
            if (j - i - 1 > mxl) {
                mxl = j - i - 1;
                ri = i + 1;
            }

            ++c;
        }
        return s.substr(ri, mxl);
    }
};

int main() {
    int n;
    string is;
    Solution s;
    cin >> n;
    while (n--) {
        cin >> is;
        cout << s.longestPalindrome(is) << endl;
    }
    return 0;
}

