/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 *
 * https://leetcode.com/problems/beautiful-arrangement/description/
 *
 * algorithms
 * Medium (53.97%)
 * Total Accepted:    34.5K
 * Total Submissions: 64K
 * Testcase Example:  '2'
 *
 * Suppose you have N integers from 1 to N. We define a beautiful arrangement
 * as an array that is constructed by these N numbers successfully if one of
 * the following is true for the ith position (1 <= i <= N) in this
 * array:
 * 
 * 
 * The number at the ith position is divisible by i.
 * i is divisible by the number at the ith position.
 * 
 * 
 * 
 * 
 * Now given N, how many beautiful arrangements can you construct?
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: 2
 * Explanation: 
 * 
 * The first beautiful arrangement is [1, 2]:
 * 
 * Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).
 * 
 * Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).
 * 
 * The second beautiful arrangement is [2, 1]:
 * 
 * Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).
 * 
 * Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * N is a positive integer and will not exceed 15.
 * 
 * 
 * 
 * 
 */
class Solution
{
  public:
    int countArrangement(int N)
    {
        vector<int> a;
        for (int i = 1; i <= N; i++)
        {
            a.push_back(i);
        }
        int res = 0;
        helper(a, res, 1);
        return res;
    }
    void helper(vector<int> &a, int &res, int pos)
    {
        if (a.size() == 0)
        {
            res++;
        }
        else
        {
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] % pos == 0 || pos % a[i] == 0)
                {
                    auto tmp = a;
                    tmp.erase(tmp.begin() + i);
                    helper(tmp, res, pos + 1);
                }
            }
        }
    }
};
