/*
 * @lc app=leetcode id=335 lang=cpp
 *
 * [335] Self Crossing
 *
 * https://leetcode.com/problems/self-crossing/description/
 *
 * algorithms
 * Hard (26.88%)
 * Total Accepted:    18.6K
 * Total Submissions: 69.1K
 * Testcase Example:  '[2,1,1,2]'
 *
 * You are given an array x of n positive numbers. You start at point (0,0) and
 * moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to
 * the south, x[3] metres to the east and so on. In other words, after each
 * move your direction changes counter-clockwise.
 * 
 * Write a one-pass algorithm with O(1) extra space to determine, if your path
 * crosses itself, or not.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * ┌───┐
 * │   │
 * └───┼──>
 * │
 * 
 * Input: [2,1,1,2]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ┌──────┐
 * │      │
 * │
 * │
 * └────────────>
 * 
 * Input: [1,2,3,4]
 * Output: false 
 * 
 * 
 * Example 3:
 * 
 * 
 * ┌───┐
 * │   │
 * └───┼>
 * 
 * Input: [1,1,1,1]
 * Output: true 
 * 
 * 
 */

/*

a lot of situations. you need to concern about.


*/ 
class Solution
{
  public:
    bool isSelfCrossing(vector<int> &x)
    {
        if (x.size() < 4)
            return false;
        pair<int, int> s = make_pair(0, 0), e = make_pair(0, x[0]);
        pair<int, int> currp = make_pair(-x[1], x[0] - x[2]);
        pair<int, int> ss = make_pair(0, 0);
        pair<int, int> sss = make_pair(0, 0);
        for (int curr = 3; curr < x.size(); curr++)
        {
            switch (curr % 4)
            {

            case 0:
            {
                pair<int, int> nextp = make_pair(currp.first, currp.second + x[curr]);
                if (nextp.first <= s.first && nextp.second >= s.second)
                    return true;
                if (nextp.first == s.first && nextp.second >= ss.second)
                    return true;
                if (nextp.first <= ss.first && nextp.first >= sss.first && nextp.second >= ss.second && currp.second <= ss.second)
                    return true;
                currp = nextp;
                sss = ss;
                ss = s;
                s = e;
                e.second -= x[curr - 2];
                break;
            }
            case 1:
            {
                pair<int, int> nextp = make_pair(currp.first - x[curr], currp.second);
                if (nextp.second <= s.second && nextp.first <= s.first)
                    return true;
                if (nextp.second == s.second && nextp.first <= ss.first)
                    return true;
                if (nextp.second >= sss.second && nextp.second <= ss.second && nextp.first <= ss.first && currp.first >= ss.first)
                    return true;
                currp = nextp;
                sss = ss;
                ss = s;
                s = e;
                e.first += x[curr - 2];
                break;
            }
            case 2:
            {
                pair<int, int> nextp = make_pair(currp.first, currp.second - x[curr]);
                if (nextp.first >= s.first && nextp.second <= s.second)
                    return true;
                if (nextp.first == s.first && nextp.second <= ss.second)
                    return true;
                if (nextp.first <= sss.first && nextp.first >= ss.first && nextp.second <= ss.second && currp.second >= ss.second)
                    return true;
                currp = nextp;
                sss = ss;
                ss = s;
                s = e;
                e.second += x[curr - 2];
                break;
            }
            case 3:
            {
                pair<int, int> nextp = make_pair(currp.first + x[curr], currp.second);
                if (nextp.second >= s.second && nextp.first >= s.first)
                    return true;
                if (nextp.second == s.second && nextp.first >= ss.first)
                    return true;
                if (nextp.second <= sss.second && nextp.second >= ss.second && nextp.first >= ss.first && currp.first <= ss.first)
                    return true;
                currp = nextp;
                sss = ss;
                ss = s;
                s = e;
                e.first -= x[curr - 2];
                break;
            }
            }
        }
        return false;
    }
};
