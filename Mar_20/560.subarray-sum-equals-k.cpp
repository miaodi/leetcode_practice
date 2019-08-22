/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (41.77%)
 * Total Accepted:    86.3K
 * Total Submissions: 206.6K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 * 
 * Example 1:
 * 
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * 
 * 
 * 
 * Note:
 * 
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 * 
 * 
 * 
 */
class Solution
{
  public:
    int subarraySum(vector<int> &nums, int k)
    {
        if (nums.empty())
            return 0;
        vector<int> sums(nums.size() + 1);
        sums[0] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sums[i + 1] = sums[i] + nums[i];
        }
        int res = 0;
        for (int i = 0; i < sums.size(); i++)
        {
            for (int j = i + 1; j < sums.size(); j++)
            {
                if (sums[j] - sums[i] == k)
                {
                    res++;
                }
            }
        }
        return res;
    }
};
