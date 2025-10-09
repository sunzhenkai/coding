/**
 * @file   3147.cpp
 * @brief  
 * @author zhenkai.sun
 * @email  zhenkai.sun@qq.com
 * @date   Fri Oct 10 07:28:00 AM CST 2025
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
      int result = INT_MIN;
      // 遍历元素
      for (int i = 0; i < energy.size(); ++i) {
        // 第 k 个元素后才开始考虑累加
        if (i >= k) {
          energy[i] += energy[i-k];
        }
        // 由于必须至少选一个, 所以最后 k 个元素强制计算结果
        if (i >= energy.size() - k) {
          result = max(result, energy[i]);
        } else {
          // 在最后 k 个元素之前，如果累加和小于 0 则置 0 （不要选择）
          if (energy[i] < 0) energy[i] = 0;
        }
      }
      return result;
    }
};

int main() {
  Solution s;
  std::vector<int> v = {1};
  std::cout << s.maximumEnergy(v, 1) << std::endl;
  v = {-2,-3,-1};
  std::cout << s.maximumEnergy(v, 2) << std::endl;
  v = {5,2,-10,-5,1};
  std::cout << s.maximumEnergy(v, 3) << std::endl;
  return 0;
}
