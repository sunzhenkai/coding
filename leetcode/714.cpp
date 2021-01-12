#include <iostream>
#include "utils.h"
#include "leetcode.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int res = 0, cb = 100000, le = 0, lb = 100000;
        for (int i = 0; i < prices.size(); ++i) {
            int cur = prices[i];

            if (cur < cb) {
                cb = cur;
                cout << "CHANGE" << endl;
                continue;
            }

            int ce = cur - cb - fee;
            cout << res << " " << cur << " " << ce << " " << lb << " " << le << endl;
            if (cur - lb - fee > le) {
                res = res - le + cur - lb - fee;


            // }
            // if (ce + le < cur - lb - fee) {
                cout << "MERGE " << res << " " << res - le + cur - lb - fee << endl;
                // res = res - le + cur - lb - fee;
                le = cur - lb - fee;
                cb = cur;
            } else if (ce > 0) {
                le = ce;
                lb = cb;
                res += ce;
                cb = cur;
                cout << "SALE" << endl;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    int fee = r<int>();
    vector<int> prices = rV<int>();
    cout << s.maxProfit(prices, fee) << endl; 
    return 0;
}
