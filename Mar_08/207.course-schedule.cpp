/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (36.75%)
 * Total Accepted:    190.3K
 * Total Submissions: 517.8K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 *
 * Example 1:
 *
 *
 * Input: 2, [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 * Example 2:
 *
 *
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 *
 *
 * Note:
 *
 *
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 *
 *
 */
class Solution
{
  public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        unordered_map<int, vector<int>> m;
        for (auto &i : prerequisites)
        {
            m[i.first].push_back(i.second);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (!helper(m, numCourses, i, 0))
                return false;
        }
        return true;
    }
    bool helper(unordered_map<int, vector<int>> &m, int numCourses, int cn,
                int steps)
    {
        if (steps >= numCourses)
            return false;
        auto it = m.find(cn);
        if (it != m.end())
        {
            bool res = true;
            for (auto j : it->second)
            {
                res = res && helper(m, numCourses, j, steps + 1);
            }
            return res;
        }
        return true;
    }
};