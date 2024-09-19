/**
 * @file   912-MergeSort.cpp
 *
 * @brief  排序数组
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Sun Mar 14 14:47:35 CST 2021
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
    void mergeSort(vector<int> &nums, int l, int r, vector<int> &res) {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        mergeSort(nums, l, mid, res);
        mergeSort(nums, mid+1, r, res);

        int i = l, j = mid + 1, c = l;
        while (i <= mid && j <= r) {
            if (nums[i] < nums[j]) {
                res[c++] = nums[i++];
            } else {
                res[c++] = nums[j++];
            }
        }

        while (i <= mid) res[c++] = nums[i++];
        while (j <= r) res[c++] = nums[j++];
        for (i = l; i <= r; ++i) {
            nums[i] = res[i];
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> res(nums.size());
        mergeSort(nums, 0, nums.size() - 1, res);
        return res;
    }
};

int main() {
    return 0;
}
