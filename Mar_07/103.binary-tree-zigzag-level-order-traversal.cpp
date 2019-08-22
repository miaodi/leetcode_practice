/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (40.52%)
 * Total Accepted:    197.2K
 * Total Submissions: 486.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
 * 
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        vector<TreeNode *> q;
        q.push_back(root);
        int arr = 0;
        while (q.size() != 0)
        {
            vector<TreeNode *> tmp;
            vector<int> curr;
            for (auto i : q)
            {
                curr.push_back(i->val);
                if (i->left != nullptr)
                    tmp.push_back(i->left);
                if (i->right != nullptr)
                    tmp.push_back(i->right);
            }
            if (arr % 2 != 0)
            {
                reverse(curr.begin(), curr.end());
            }
            res.push_back(curr);
            arr++;
            q = tmp;
        }
        return res;
    }
};
