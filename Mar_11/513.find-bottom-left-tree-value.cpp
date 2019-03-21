/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 *
 * https://leetcode.com/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (57.98%)
 * Total Accepted:    66.2K
 * Total Submissions: 114.2K
 * Testcase Example:  '[2,1,3]'
 *
 * 
 * Given a binary tree, find the leftmost value in the last row of the tree. 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Output:
 * 1
 * 
 * 
 * 
 * ⁠ Example 2: 
 * 
 * Input:
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   5   6
 * ⁠      /
 * ⁠     7
 * 
 * Output:
 * 7
 * 
 * 
 * 
 * Note:
 * You may assume the tree (i.e., the given root node) is not NULL.
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
class Solution
{
  public:
    int findBottomLeftValue(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        vector<TreeNode *> s;
        s.push_back(root);
        int res = 0;
        while (s.size() != 0)
        {
            res = s[0]->val;
            vector<TreeNode *> tmp;
            for (auto &i : s)
            {
                if (i->left != nullptr)
                    tmp.push_back(i->left);
                if (i->right != nullptr)
                    tmp.push_back(i->right);
            }
            s = tmp;
        }
        return res;
    }
};
