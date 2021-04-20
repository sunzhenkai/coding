/**
 * @file   05.cpp
 *
 * @brief  替换空格
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Tue Apr 20 22:00:32 CST 2021
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string res(s.length() * 3 + 1, '\0');
        int j = 0;
        for (int i = 0; i < s.length; ++i) {
            if (s[i] == ' ') {
                s[j++] = '%';
                s[j++] = '2';
                s[j++] = '0';
            } else {
                s[j++] = s[i];
            }
        }
        s.resize(j);
        return res;
    }
};

int main() {
    return 0;
}
