/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 *
 * https://leetcode.com/problems/valid-mountain-array/description/
 *
 * algorithms
 * Easy (34.95%)
 * Total Accepted:    15.1K
 * Total Submissions: 43.3K
 * Testcase Example:  '[2,1]'
 *
 * Given an array A of integers, return true if and only if it is a valid
 * mountain array.
 * 
 * Recall that A is a mountain array if and only if:
 * 
 * 
 * A.length >= 3
 * There exists some i with 0 < i < A.length - 1 such that:
 * 
 * A[0] < A[1] < ... A[i-1] < A[i] 
 * A[i] > A[i+1] > ... > A[B.length - 1]
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [2,1]
 * Output: false
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,5,5]
 * Output: false
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [0,3,2,1]
 * Output: true
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A.length <= 10000
 * 0 <= A[i] <= 10000 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class Solution
{
  public:
    bool validMountainArray(vector<int> &A)
    {
        if (A.size() < 3)
            return false;
        auto it = A.begin();
        while (it != A.end() - 1)
        {
            if (*it < *(it + 1))
            {
                it++;
            }
            else
            {
                break;
            }
        }
        if (it == A.end() - 1)
            return false;
        auto rit = A.end() - 1;
        while (rit != A.begin())
        {
            if (*rit < *(rit - 1))
            {
                rit--;
            }
            else
            {
                break;
            }
        }
        if(rit == A.begin()) return false;
        return it==rit;
    }
};
