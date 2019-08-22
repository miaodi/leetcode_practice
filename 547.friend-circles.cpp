/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
 */
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &M)
    {
        if (M.empty())
            return 0;
        vector<bool> bv(M.size(), false);
        int res = 0;
        for (int i = 0; i < bv.size(); i++)
        {
            if (bv[i] == false)
            {
                helper(M, bv, i);
                res++;
            }
        }
        return res;
    }
    void helper(const vector<vector<int>> &M, vector<bool> &bv, int i)
    {
        if (bv[i] == true)
            return;
        bv[i] = true;
        for (int j = 0; j < bv.size(); j++)
        {
            if (M[i][j] == 1)
            {
                helper(M, bv, j);
            }
        }
    }
};
