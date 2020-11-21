#include <iostream>
#include "utils.h"
#include "leetcode.h"

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {        
        int len = s.length();
        int v[len][len];
        memset(v, 0, sizeof(v));
        
        v[0][1] = 1;
        for (int i = 1; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                v[i][j] = v[i-1][j] + v[i][j-1] + (s[i] == s[j] ? 2 : 0);
            }
        }
    }
};

int main() {
    return 0;
}
