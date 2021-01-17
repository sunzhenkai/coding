/**
 * @file   0004.cpp
 *
 * @brief  寻找两个正序数组的中位数
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Sat Jan 16 12:55:59 CST 2021
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int ll = nums1.size(), lr = nums2.size();
        int ls = ll + lr, ml, mr;
        int pi = 0, pj  = 0;
        double sum = 0;
        if (ls % 2 == 0) {
            ml = ls / 2 - 1;
            mr = ml + 1;
        } else {
            ml = mr = (ls + 1) / 2 - 1;
        }
        // cout << "ml: " << ml << ", mr: " << mr << endl;

        while (pi + pj <= mr) {
            if (pi >= ll || (pj < lr && nums1[pi] >= nums2[pj])) {
                if (pi + pj == ml || pi + pj == mr) sum += nums2[pj];
                ++pj;
            } else if (pj >= lr || nums1[pi] < nums2[pj]) {
                if (pi + pj == ml || pi + pj == mr) sum += nums1[pi];
                ++pi;
            } 
        }
        return sum / (mr - ml + 1);
    }
};

int main() {
    int n;
    Solution s;
    cin >> n;
    while (n--) {
        vector<int> nums1 = rNV<int>();
        vector<int> nums2 = rNV<int>();
        pV(nums1);
        pV(nums2);
        cout << s.findMedianSortedArrays(nums1, nums2) << endl;

    }
    return 0;
}
