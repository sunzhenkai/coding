/**
 * @file   010.cpp
 *
 * @brief  正则表达式匹配
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Sun Jan 17 16:06:45 CST 2021
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    bool isMatch(string &s, string &p, int l, int r) {
        if (p.size() == r) return s.size() == l;

        bool fm = s.size() > l && (s[l] == p[r] || p[r] == '.');
        if (r + 1 < p.size() && p[r+1] == '*') {
            return isMatch(s, p, l, r + 2) || (fm && isMatch(s, p, l+1, r));
        } else {
            return fm && isMatch(s, p, l + 1, r + 1);
        }
    }

    bool isMatch(string s, string p) {
        return isMatch(s, p, 0, 0);
    }
};

int main() {
    Solution s;
    string a, b;

    while (cin >> a >> b) {
        cout << a << " - " << b << endl;
        cout << s.isMatch(a, b) << endl;
    }
    return 0;
}
