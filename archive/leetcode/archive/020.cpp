/**
 * @file   020.cpp
 *
 * @brief  有效的括号
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Thu Jan 21 22:28:52 CST 2021
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
    static map<char, char> pr;
public:
    bool isValid(string s) {
        char stack[s.size()];
        int idx = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (idx == -1 || stack[idx] != pr[s[i]]) stack[++idx] = s[i];
            else if (stack[idx] == pr[s[i]]) --idx;
            else return false;
        }
        return idx == -1;
    }
};
map<char, char> Solution::pr = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

int main() {
    Solution s;
    string ipt;
    while (cin >> ipt) {
        cout << s.isValid(ipt) << endl;
    }
    return 0;
}
