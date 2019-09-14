/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;

        helper(n, k, 0, res, vector<int>{});
        return res;
    }
    void helper(int n, int k, int pos, vector<vector<int>> &res, const vector<int> &cur)
    {
        if (cur.size() == k)
        {
            res.emplace_back(cur);
        }
        else
        {
            for (int i = pos + 1; i <= n - (k - cur.size() - 1); ++i)
            {
                auto tmp = cur;
                tmp.push_back(i);
                helper(n, k, i, res, tmp);
            }
        }
    }
};
