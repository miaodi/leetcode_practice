/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 *
 * https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/description/
 *
 * algorithms
 * Easy (48.41%)
 * Total Accepted:    5K
 * Total Submissions: 10.2K
 * Testcase Example:  '[4,2,3]\n1'
 *
 * Given an array A of integers, we must modify the array in the following way:
 * we choose an i and replace A[i] with -A[i], and we repeat this process K
 * times in total.  (We may choose the same index i multiple times.)
 *
 * Return the largest possible sum of the array after modifying it in this
 * way.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: A = [4,2,3], K = 1
 * Output: 5
 * Explanation: Choose indices (1,) and A becomes [4,-2,3].
 *
 *
 *
 * Example 2:
 *
 *
 * Input: A = [3,-1,0,2], K = 3
 * Output: 6
 * Explanation: Choose indices (1, 2, 2) and A becomes [3,1,0,2].
 *
 *
 *
 * Example 3:
 *
 *
 * Input: A = [2,-3,-1,5,-4], K = 2
 * Output: 13
 * Explanation: Choose indices (1, 4) and A becomes [2,3,-1,5,4].
 *
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 10000
 * 1 <= K <= 10000
 * -100 <= A[i] <= 100
 *
 *
 */
class Solution
{
  public:
    int largestSumAfterKNegations(vector<int> &A, int K)
    {
        sort(A.begin(), A.end());
        bool zero = false;
        int n = INT_MAX, p = INT_MAX;
        for (int i = 0; i < A.size(); i++)
        {
            if (K == 0)
                break;
            if (A[i] > 0)
            {
                p = A[i];
                break;
            }
            if (A[i] < 0)
            {
                A[i] *= -1;
                n = A[i];
                K--;
            }
            if (A[i] == 0)
                zero = true;
        }

        int res = 0;
        for (auto i : A)
        {
            res += i;
        }
        if (K == 0 || zero || K % 2 == 0)
            return res;
        return n > p ? res - 2 * p : res - 2 * n;
    }
};
