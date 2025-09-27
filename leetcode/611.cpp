/**
 * @file   611.cpp
 * @brief
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Sat Sep 27 10:13:28 AM CST 2025
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
  // TODO
  int bin_search(const std::vector<int>& nums, int l, int r, int target) {
    while (l < r) {
      int mid = (l + r) / 2 + 1;
      if (nums[mid] >= target) {
        r = mid - 1;
      } else {
        l = mid;
      }
    }
    return l;
  }

 public:
  int triangleNumber(vector<int>& nums) {
    int result{0};
    if (nums.size() < 3) return 0;
    std::sort(nums.begin(), nums.end());
    int i = 0;
    while (nums[i] == 0 && i < nums.size()) ++i;
    for (; i < nums.size() - 2; i++) {
      for (int j = i + 1; j < nums.size() - 1; ++j) {
        // 找到 nums[k] < nums[i] + nums[j] 的最大坐标
        int k = bin_search(nums, j, nums.size() - 1, nums[i] + nums[j]);
        result += k - j;
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  std::vector<int> nums{2, 2, 3, 4};
  auto a = s.triangleNumber(nums);
  std::cout << a << std::endl;

  nums = {4, 2, 3, 4};
  a = s.triangleNumber(nums);
  std::cout << a << std::endl;

  nums = {2, 3, 4};
  a = s.triangleNumber(nums);
  std::cout << a << std::endl;
  return 0;
}

/*
 * OUTPUT
wii 🌐 work coding/leetcode  master [?] via C v13.3.0-gcc ❯ mk 611
3
4
1
 * */
