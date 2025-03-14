#include <cstddef>
#include <iostream>
#include <iterator>
#include <unordered_map>

#include "../template/leetcode.h"
#include "../template/utils.h"

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int, int> store;
    for (size_t i = 0ul; i < nums.size(); ++i) {
      auto& num = nums[i];
      auto idx = store[num];
      if (idx > 0) {
        return {idx - 1, int(i)};
      } else {
        store[target - num] = i + 1;
      }
    }
    return {};
  }
};

int main() {
  // mock data
  std::vector<int> v = {2, 7, 11, 15};
  int target = 9;
  Solution s;
  printVector(s.twoSum(v, target));
  return 0;
}
