/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> flag(n, true);
        for (int i = 2; i < n; ++i) {
            if (!flag[i]) continue;
            ++res;
            for (long long j = (long long)i * i; j < n; j += i) {
                flag[j] = false;
            }
        }

        return res;

        // vector<bool> flag(n, 1);
        // for (int i = 2; i <= sqrt(n);) {
        //     for (int j = i * i; j < n; j += 2 * i) {
        //         flag[j] = 0;
        //     }

        //     while (!flag[++i]);
        // }

        // int res = 0;
        // for (int i = 2; i < n; ++i) {
        //     if (flag[i]) ++res;
        // }
        // return res;
    }
};
// @lc code=end

