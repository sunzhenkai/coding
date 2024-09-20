#include <iostream>
#include <stack>
#include <vector>

void display(const std::vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        if (i != 0) std::cout << " ";
        std::cout << nums[i];
    }
    std::cout << std::endl;
}

class Solution {
    public:
        std::vector<int> solve(const std::vector<int> &nums, int k) {
            std::vector<int> result;
            std::stack<std::pair<int, int>> info;
            for (int i = 0; i < nums.size();) {
                if (info.empty()) {
                    info.push({nums[i], 1});
                    ++i;
                } else if (info.top().first == nums[i]) {
                    ++info.top().second;
                    ++i;
                } else if (info.top().second >= k) {
                    info.pop();
                } else {
                    info.push({nums[i], 1});
                    ++i;
                }
            }
            while (!info.empty()) {
                if (info.top().second < k) {
                    for (int i = 0; i < info.top().second; ++i) result.emplace_back(info.top().first);
                }
                info.pop();
            }
            return result;
        }
};

int main() {
    Solution s;
    display(s.solve({1, 2, 2, 3}, 2));
    display(s.solve({1, 2, 3, 3, 2, 3}, 2));
    display(s.solve({1, 2, 2, 2, 3}, 3));
    display(s.solve({1, 2, 2, 3}, 1));
    return 0;
}
