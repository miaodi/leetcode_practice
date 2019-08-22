/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 *
 * https://leetcode.com/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (41.73%)
 * Total Accepted:    35.6K
 * Total Submissions: 85.4K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * Given an array which consists of non-negative integers and an integer m, you
 * can split the array into m non-empty continuous subarrays. Write an
 * algorithm to minimize the largest sum among these m subarrays.
 *
 *
 * Note:
 * If n is the length of array, assume the following constraints are
 * satisfied:
 *
 * 1 ≤ n ≤ 1000
 * 1 ≤ m ≤ min(50, n)
 *
 *
 *
 * Examples:
 *
 * Input:
 * nums = [7,2,5,10,8]
 * m = 2
 *
 * Output:
 * 18
 *
 * Explanation:
 * There are four ways to split nums into two subarrays.
 * The best way is to split it into [7,2,5] and [10,8],
 * where the largest sum among the two subarrays is only 18.
 *
 *
 */
// DP solution
class Solution
{
  public:
    int splitArray(vector<int> &nums, int m)
    {
        if (nums.size() == 0)
            return 0;
        vector<vector<long>> dp(m, vector<long>(nums.size()));
        dp[0][0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[0][i] = dp[0][i - 1] + nums[i];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                long res = LONG_MAX;
                for (int k = i; k <= j; k++)
                {
                    long tmp = max(dp[i-1][k-1], dp[0][j]-dp[0][k-1]);
                    res = min(tmp, res);
                }
                dp[i][j] = res;
            }
        }
        return dp[m-1][nums.size()-1];
    }

    // DFS
    int helper(vector<long> &sums, int m, int pos, int el, long ma)
    {
        if (pos > sums.size() - 2)
            return INT_MAX;
        if (el == m - 1)
        {
            return max(ma, sums.back() - sums[pos]);
        }
        else
        {
            int res = INT_MAX;
            for (int i = pos + 1; i < sums.size(); i++)
            {
                auto tmp = max(ma, sums[i] - sums[pos]);
                res = min(res, helper(sums, m, i, el + 1, tmp));
            }
            return res;
        }
    }
};
