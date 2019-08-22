/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 *
 * https://leetcode.com/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (47.72%)
 * Total Accepted:    98.4K
 * Total Submissions: 206.2K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * The thief has found himself a new place for his thievery again. There is
 * only one entrance to this area, called the "root." Besides the root, each
 * house has one and only one parent house. After a tour, the smart thief
 * realized that "all houses in this place forms a binary tree". It will
 * automatically contact the police if two directly-linked houses were broken
 * into on the same night.
 * 
 * Determine the maximum amount of money the thief can rob tonight without
 * alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3,null,3,null,1]
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  2   3
 * ⁠   \   \ 
 * ⁠    3   1
 * 
 * Output: 7 
 * Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,5,1,3,null,1]
 * 
 * 3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \   \ 
 * ⁠1   3   1
 * 
 * Output: 9
 * Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// need memoization
class Solution
{
    unordered_map<TreeNode *, int> m;

  public:
    int rob(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        auto it = m.find(root);
        if (it != m.end())
        {
            return it->second;
        }
        int val = root->val;
        if (root->left != nullptr)
        {
            val += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right != nullptr)
        {
            val += rob(root->right->left) + rob(root->right->right);
        }
        val = max(val, rob(root->left) + rob(root->right));
        m[root] = val;
        return max(val, rob(root->left) + rob(root->right));
    }
};
