/**
 * @file   03.cpp
 *
 * @brief  数组中重复的数字
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Sun Apr 18 20:59:40 CST 2021
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
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size();) {
            int cur = nums[i];
            if (cur < 0) { i++; continue;}
            if (nums[cur] < 0) return cur;
            swap(nums[i], nums[cur]);
            nums[cur] = -1;
        }
        return -1;
    }
};
