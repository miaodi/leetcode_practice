/*
 * @lc app=leetcode id=849 lang=cpp
 *
 * [849] Maximize Distance to Closest Person
 *
 * https://leetcode.com/problems/maximize-distance-to-closest-person/description/
 *
 * algorithms
 * Easy (40.47%)
 * Total Accepted:    28.1K
 * Total Submissions: 69.4K
 * Testcase Example:  '[1,0,0,0,1,0,1]'
 *
 * In a row of seats, 1 represents a person sitting in that seat, and 0
 * represents that the seat is empty. 
 * 
 * There is at least one empty seat, and at least one person sitting.
 * 
 * Alex wants to sit in the seat such that the distance between him and the
 * closest person to him is maximized. 
 * 
 * Return that maximum distance to closest person.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,0,0,0,1,0,1]
 * Output: 2
 * Explanation: 
 * If Alex sits in the second open seat (seats[2]), then the closest person has
 * distance 2.
 * If Alex sits in any other open seat, the closest person has distance 1.
 * Thus, the maximum distance to the closest person is 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,0,0,0]
 * Output: 3
 * Explanation: 
 * If Alex sits in the last seat, the closest person is 3 seats away.
 * This is the maximum distance possible, so the answer is 3.
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= seats.length <= 20000
 * seats contains only 0s or 1s, at least one 0, and at least one 1.
 * 
 * 
 * 
 * 
 */
class Solution
{
  public:
    int maxDistToClosest(vector<int> &seats)
    {
        int max_dist = 0;
        int dist = 0;
        auto it = seats.begin(), rit = seats.end() - 1;
        while (*it == 0)
        {
            it++;
        }
        while (*rit == 0)
        {
            rit--;
        }
        max_dist = max(it - seats.begin(), seats.end() - 1 - rit);
        for (auto iter = it; iter != rit + 1; iter++)
        {
            if (*iter == 1)
            {
                dist++;//important
                max_dist = max(max_dist, dist / 2);
                dist = 0;
            }
            else
            {
                dist++;
            }
        }
        return max_dist;
    }
};
