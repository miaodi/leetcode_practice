/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (45.12%)
 * Total Accepted:    185.6K
 * Total Submissions: 411.3K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */
class Solution
{
  public:
    int numTrees(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += numTrees(i) * numTrees(n - i - 1); //left are numbers on the left of the tree, right are numbers on the right of the tree.
        }
        return res;
    }
    //  use dp to speed up.
    int numTrees(int n)
    {
        vector<int> ff(n + 1);
        ff[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                ff[i] += ff[j] * ff[i - j - 1];
            }
        }
        return ff[n];
    }
};
