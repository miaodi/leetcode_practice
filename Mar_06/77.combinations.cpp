/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (46.08%)
 * Total Accepted:    186.6K
 * Total Submissions: 405K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
//  this one should be improved.
class Solution
{
  public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        if (k > n)
            return res;
        vector<int> a;
        for (int i = 1; i <= n; i++)
        {
            a.push_back(i);
        }
        vector<int> b;
        helper(a, 0, k, res, b);
        return res;
    }
    void helper(vector<int> &a, int curr, int tot, vector<vector<int>> &res, vector<int> &b)
    {
        if (curr == tot)
        {
            res.push_back(b);
        }
        else
        {
            for (int i = 0; i < a.size(); i++)
            {
                if(b.size()>0&&a[i]<b.back()) continue;
                auto tmp = a;
                auto tmp1 = b;
                tmp1.push_back(a[i]);
                tmp.erase(tmp.begin() + i);
                helper(tmp, curr + 1, tot, res, tmp1);
            }
        }
    }
};
