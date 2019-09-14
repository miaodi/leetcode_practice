/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> res;
        res.push_back(0);
        if (num == 0)
            return res;
        for (int i = 1; i <= num; i++)
        {
            if (i % 2)
            {
                res.push_back(res[i / 2] + 1);
            }
            else
            {
                res.push_back(res[i / 2]);
            }
        }
        return res;
    }
};
