/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        if (prerequisites.empty())
            return true;
        vector<set<int>> pre(numCourses);
        for (auto i : prerequisites)
        {
            pre[i[0]].insert(i[1]);
        }
        set<int> visited;
        set<int> current;
        for (int i = 0; i < numCourses; i++)
        {
            if (pre[i].size() == 1)
                current.insert(i);
        }
        while (true)
        {
            set<int> next;
            for (auto i : current)
            {
                for (auto j : pre[i])
                {
                    if (visited.count(j))
                        return false;
                    next.insert(j);
                }
            }
            if (next.size() == 0)
                return true;
            for (auto i : current)
            {
                visited.insert(i);
            }
            current = move(next);
        }
        return false;
    }
};
