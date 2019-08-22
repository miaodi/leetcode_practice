/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (51.90%)
 * Total Accepted:    76.7K
 * Total Submissions: 147.8K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 9
 * 
 * Output: True
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 28
 * 
 * Output: False
 * 
 * 
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
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> s;
        helper(root, s);
        if (s.size() < 2)
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < s.size(); j++)
            {
                if (i == j)
                    continue;
                if (s[i] + s[j] > k)
                    break;
                if (s[i] + s[j] == k)
                    return true;
            }
        }
        return false;
    }
    void helper(TreeNode *root, vector<int> &s)
    {
        if (root == nullptr)
            return;
        helper(root->left, s);
        s.push_back(root->val);
        helper(root->right, s);
    }
};
