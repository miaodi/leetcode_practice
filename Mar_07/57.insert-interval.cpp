/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (30.77%)
 * Total Accepted:    165.3K
 * Total Submissions: 537K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
    {
        intervals.push_back(newInterval);
        vector<Interval> res;
        if (intervals.size() == 1)
            return intervals;
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
