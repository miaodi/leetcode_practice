/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (34.81%)
 * Total Accepted:    128.7K
 * Total Submissions: 369.6K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
    vector<TreeNode *> generateTrees(int n)
    {
        return generateTrees1(n, 0);
    }
    vector<TreeNode *> generateTrees1(int n, int offset)
    {
        vector<TreeNode *> res;
        if (n == 0)
        {
            return res;
        }
        if (n == 1)
        {
            res.push_back(new TreeNode(1 + offset));
            return res;
        }
        for (int i = 0; i < n; i++)
        {
            auto left = generateTrees1(i, offset);
            auto right = generateTrees1(n - i - 1, offset + i + 1);
            if (left.size() == 0)
                left.push_back(nullptr);
            if (right.size() == 0)
                right.push_back(nullptr);
            for (int j = 0; j < right.size(); j++)
            {
                for (int k = 0; k < left.size(); k++)
                {
                    auto root = new TreeNode(i + 1 + offset);
                    root->left = left[k];
                    root->right = right[j];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
