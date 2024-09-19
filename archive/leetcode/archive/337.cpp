/**
 * @file   337.cpp
 *
 * @brief  打家劫舍 III
 *
 * @author wii
 *
 * @email  zhenkai.sun@qq.com
 *
 * @date   Sun Mar 14 15:15:50 CST 2021
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct Status {
    int select;
    int notSelect;
};

class Solution {
    Status solve(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        if (root->left == nullptr && root->right == nullptr) {
            return {root->val, 0};
        }

        Status sl = solve(root->left);
        Status sr = solve(root->right);
        return {sl.notSelect + sr.notSelect + root->val, max(sl.select, sl.notSelect) + max(sr.select, sr.notSelect)};
    }
public:
    int rob(TreeNode* root) {
        Status s = solve(root);
        return max(s.select, s.notSelect);
    }
};

int main() {
    return 0;
}
