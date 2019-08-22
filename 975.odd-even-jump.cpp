/*
 * @lc app=leetcode id=975 lang=cpp
 *
 * [975] Odd Even Jump
 *
 * https://leetcode.com/problems/odd-even-jump/description/
 *
 * algorithms
 * Hard (50.24%)
 * Total Accepted:    6K
 * Total Submissions: 12K
 * Testcase Example:  '[10,13,12,14,15]'
 *
 * You are given an integer array A.  From some starting index, you can make a
 * series of jumps.  The (1st, 3rd, 5th, ...) jumps in the series are called
 * odd numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the series are
 * called even numbered jumps.
 *
 * You may from index i jump forward to index j (with i < j) in the following
 * way:
 *
 *
 * During odd numbered jumps (ie. jumps 1, 3, 5, ...), you jump to the index j
 * such that A[i] <= A[j] and A[j] is the smallest possible value.  If there
 * are multiple such indexes j, you can only jump to the smallest such index
 * j.
 * During even numbered jumps (ie. jumps 2, 4, 6, ...), you jump to the index j
 * such that A[i] >= A[j] and A[j] is the largest possible value.  If there are
 * multiple such indexes j, you can only jump to the smallest such index j.
 * (It may be the case that for some index i, there are no legal jumps.)
 *
 *
 * A starting index is good if, starting from that index, you can reach the end
 * of the array (index A.length - 1) by jumping some number of times (possibly
 * 0 or more than once.)
 *
 * Return the number of good starting indexes.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [10,13,12,14,15]
 * Output: 2
 * Explanation:
 * From starting index i = 0, we can jump to i = 2 (since A[2] is the smallest
 * among A[1], A[2], A[3], A[4] that is greater or equal to A[0]), then we
 * can't jump any more.
 * From starting index i = 1 and i = 2, we can jump to i = 3, then we can't
 * jump any more.
 * From starting index i = 3, we can jump to i = 4, so we've reached the end.
 * From starting index i = 4, we've reached the end already.
 * In total, there are 2 different starting indexes (i = 3, i = 4) where we can
 * reach the end with some number of jumps.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [2,3,1,1,4]
 * Output: 3
 * Explanation:
 * From starting index i = 0, we make jumps to i = 1, i = 2, i = 3:
 *
 * During our 1st jump (odd numbered), we first jump to i = 1 because A[1] is
 * the smallest value in (A[1], A[2], A[3], A[4]) that is greater than or equal
 * to A[0].
 *
 * During our 2nd jump (even numbered), we jump from i = 1 to i = 2 because
 * A[2] is the largest value in (A[2], A[3], A[4]) that is less than or equal
 * to A[1].  A[3] is also the largest value, but 2 is a smaller index, so we
 * can only jump to i = 2 and not i = 3.
 *
 * During our 3rd jump (odd numbered), we jump from i = 2 to i = 3 because A[3]
 * is the smallest value in (A[3], A[4]) that is greater than or equal to
 * A[2].
 *
 * We can't jump from i = 3 to i = 4, so the starting index i = 0 is not good.
 *
 * In a similar manner, we can deduce that:
 * From starting index i = 1, we jump to i = 4, so we reach the end.
 * From starting index i = 2, we jump to i = 3, and then we can't jump anymore.
 * From starting index i = 3, we jump to i = 4, so we reach the end.
 * From starting index i = 4, we are already at the end.
 * In total, there are 3 different starting indexes (i = 1, i = 3, i = 4) where
 * we can reach the end with some number of jumps.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: [5,1,3,4,2]
 * Output: 3
 * Explanation:
 * We can reach the end from starting indexes 1, 2, and 4.
 *
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length <= 20000
 * 0 <= A[i] < 100000
 *
 */
class Solution
{
  public:
    int oddEvenJumps(vector<int> &A)
    {
        set<int> odd_true, odd_false, even_true, even_false;
        odd_true.insert(A.size() - 1);
        even_true.insert(A.size() - 1);
        int res = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (helper(odd_true, odd_false, even_true, even_false, true, A,
                       0, i))
            {
                res++;
            }
        }
        return res;
    }
    bool helper(set<int> &odd_true, set<int> &odd_false, set<int> &even_true,
                set<int> &even_false, bool odd, vector<int> &A, int stp,
                int pos)
    {
        if (stp > 2 * A.size())
            return false;
        if (odd)
        {
            auto it_t = odd_true.find(pos);
            auto it_f = odd_false.find(pos);
            if (it_t == odd_true.end() && it_f == odd_false.end())
            {
                int np, test = INT_MAX;
                for (int i = A.size() - 1; i >= 0; i--)
                {
                    if (i == pos)
                        continue;
                    if (A[i] >= A[pos])
                    {
                        if (test >= A[i])
                        {
                            np = i;
                            test = A[i];
                        }
                    }
                }
                if (np == pos || A[np] == INT_MAX)
                {
                    odd_false.insert(pos);
                    return false;
                }
                else
                {
                    auto value = A[pos];
                    A[pos] = INT_MAX;
                    bool tmp = helper(odd_true, odd_false, even_true, even_false, !odd, A,
                                      stp + 1, np);
                    A[pos] = value;
                    if (tmp)
                    {
                        odd_true.insert(pos);
                    }
                    else
                    {
                        odd_false.insert(pos);
                    }
                    return tmp;
                }
            }
            else if (it_t != odd_true.end())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            auto it_t = even_true.find(pos);
            auto it_f = even_false.find(pos);
            if (it_t == even_true.end() && it_f == even_false.end())
            {
                int np, test = INT_MIN;
                for (int i = A.size() - 1; i >= 0; i--)
                {
                    if (i == pos)
                        continue;
                    if (A[i] <= A[pos])
                    {
                        if (test <= A[i])
                        {
                            np = i;
                            test = A[i];
                        }
                    }
                }
                if (np == pos || A[np] == INT_MAX)
                {
                    even_false.insert(pos);
                    return false;
                }
                else
                {
                    auto value = A[pos];
                    A[pos] = INT_MAX;
                    bool tmp = helper(odd_true, odd_false, even_true, even_false, !odd, A,
                                      stp + 1, np);
                    A[pos] = value;
                    if (tmp)
                    {
                        even_true.insert(pos);
                    }
                    else
                    {
                        even_false.insert(pos);
                    }
                    return tmp;
                }
            }
            else if (it_t != even_true.end())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};
