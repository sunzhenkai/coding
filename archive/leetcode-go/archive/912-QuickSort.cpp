/**
 * @file   912-QuickSort.cpp
 *
 * @brief  排序数组
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Sun Mar 14 14:31:21 CST 2021
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
    void qs(vector<int> &v, int l, int r) {
        if (l >= r) return;
        int i = l, j = r, pivot = v[l];
        while (i != j) {
            while (j > i && v[j] >= pivot) --j;
            v[i] = v[j];
            while (j > i && v[i] <= pivot) ++i;
            v[j] = v[i];
        }

        v[i] = pivot;
        qs(v, l, i-1);
        qs(v, i+1, r);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        qs(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    return 0;
}
