/**
 * @file   04.cpp
 *
 * @brief  二维数组查找
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Tue Apr 20 21:41:53 CST 2021
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
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int r = 0, c = matrix[0].size();
        while (r < matrix.size() && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            } else if (matric[r][c] > target) {
                --c;
            } else {
                ++r;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
