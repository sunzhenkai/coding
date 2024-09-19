/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int la(a.length()-1), lb(b.length()-1);
        short sum(0);
        string res("");
        while (la >= 0 || lb >= 0 || sum > 0) {
            if (la >= 0) sum += a[la--] - '0';
            if (lb >= 0) sum += b[lb--] - '0';
            res = (char)('0' + sum % 2) + res;
            sum /= 2;
        }
        return res;
    }
};
// @lc code=end

