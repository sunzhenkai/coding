#include <iostream>
#include "utils.h"
#include "leetcode.h"

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        for (int idx = 0; idx < strs[0].length(); ++idx) {
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i].length() <= idx || strs[i][idx] != strs[0][idx]) {
                    return strs[0].substr(0, idx);
                }
            }
        }
        return strs[0];
    }
};

int main() {
    vector<string> v = rV<string>();
    Solution s;
    cout << s.longestCommonPrefix(v) << endl;
    return 0;
}
