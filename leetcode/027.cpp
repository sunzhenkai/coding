/**
 * @file   027.cpp
 *
 * @brief  移除元素
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Sat Jan 23 12:39:40 CST 2021
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
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for (int j=0; j < nums.size(); ++j) {
            if (nums[j] != val)
                nums[i++] = nums[j];
        }
        return i;
    }
};

int main() {
    int n, val;
    Solution s;
    cin >> n;
    while (n--) {
        cin >> val;
        vector<int> v = rNV<int>();
        cout << s.removeElement(v, val) << endl;
    }
    return 0;
}
