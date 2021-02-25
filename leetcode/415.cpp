/**
 * @file   315.cpp
 *
 * @brief  字符串相加
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Thu Feb 25 21:56:10 CST 2021
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int ml = max(num1.length(), num2.length());
        int pos = ml - 1, i = num1.length() - 1, j = num2.length() - 1;
        int upgrade = 0;
        string res(ml, '0');

        while (i >= 0 || j >= 0) {
            int cur = upgrade;
            cur += i >= 0 ? num1[i] - '0' : 0;
            cur += j >= 0 ? num2[j] - '0' : 0;
            upgrade = cur / 10;
            res[pos] += cur % 10;
            --pos; --i; --j;
        }
        return upgrade > 0 ? (char)('0' + upgrade) + res : res;
    }
};

int main() {
    Solution s;
    string sa, sb;
    while (cin >> sa >> sb) {
        string res = s.addStrings(sa, sb);
        cout << res << endl;
    }
    return 0;
}
