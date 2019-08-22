/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 *
 * https://leetcode.com/problems/continuous-subarray-sum/description/
 *
 * algorithms
 * Medium (24.14%)
 * Total Accepted:    59.3K
 * Total Submissions: 245.5K
 * Testcase Example:  '[23,2,4,6,7]\n6'
 *
 *
 * Given a list of non-negative numbers and a target integer k, write a
 * function to check if the array has a continuous subarray of size at least 2
 * that sums up to the multiple of k, that is, sums up to n*k where n is also
 * an integer.
 *
 *
 *
 * Example 1:
 *
 * Input: [23, 2, 4, 6, 7],  k=6
 * Output: True
 * Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up
 * to 6.
 *
 *
 *
 *
 * Example 2:
 *
 * Input: [23, 2, 6, 4, 7],  k=6
 * Output: True
 * Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5
 * and sums up to 42.
 *
 *
 *
 * Note:
 *
 * The length of the array won't exceed 10,000.
 * You may assume the sum of all the numbers is in the range of a signed 32-bit
 * integer.
 *
 *
 */
class Solution
{
  public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        if (nums.size() == 0)
            return false;
        vector<int> sums(nums.size() + 1);
        sums[0] = 0;
        for (int i = 1; i <= nums.size(); i++)
        {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 0; i < sums.size(); i++)
        {
            for (int j = i + 2; j < sums.size(); j++)
            {
                if (k == 0 && (sums[j] - sums[i]) == 0)
                    return true;
                if (k != 0 && (sums[j] - sums[i]) % k == 0)
                    return true;
            }
        }
        return false;
    }
};
