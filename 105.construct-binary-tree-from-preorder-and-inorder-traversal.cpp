/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (39.84%)
 * Total Accepted:    206K
 * Total Submissions: 517.1K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *root = nullptr;
        int pos = 0;
        helper(root, preorder, pos, inorder.begin(), inorder.end());
        return root;
    }
    void helper(TreeNode *&root, vector<int> &preorder, int& pos, vector<int>::iterator l, vector<int>::iterator r)
    {
        if (l == r)
        {
            return;
        }
        root = new TreeNode(preorder[pos]);
        auto it = find(l, r, root->val);
        pos++;
        helper(root->left, preorder, pos, l, it);
        helper(root->right, preorder, pos, it + 1, r);
    }
};
