/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        vector<int> t(nums.size(), 0), f(nums.size(), 0);
        t[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            f[i] = max(t[i - 1], f[i - 1]);
            t[i] = f[i - 1] + nums[i];
        }
        return max(f.back(), t.back());
    }
};
