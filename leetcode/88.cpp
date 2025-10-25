/**
 * @file   88.cpp
 * @brief
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Sat Oct 25 11:32:48 AM CST 2025
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i1 = m - 1;
    int i2 = n - 1;
    for (int i = m + n - 1; i >= 0; --i) {
      if (i2 < 0 || (i1 >= 0 && nums1[i1] > nums2[i2])) {
        nums1[i] = nums1[i1--];
      } else {
        nums1[i] = nums2[i2--];
      }
    }
  }
};

int main() { return 0; }
