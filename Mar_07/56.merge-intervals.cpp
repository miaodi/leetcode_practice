/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (34.87%)
 * Total Accepted:    309.5K
 * Total Submissions: 887.6K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution
{
  public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        vector<Interval> res;
        if (intervals.size() == 0)
            return res;
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) { return a.start < b.start; });
        res.push_back(intervals[0]);
        for (auto &i : intervals)
        {
            if (i.start > res.back().end)
            {
                res.push_back(i);
            }
            else
            {
                res.back().end = max(i.end, res.back().end);
            }
        }
        return res;
    }
};
