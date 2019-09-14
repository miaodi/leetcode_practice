/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */
class Solution
{

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<int> res;
        // corner cases
        if (n == 0)
            return res;
        if (n == 1)
        {
            res.push_back(0);
            return res;
        }
        if (n == 2)
        {
            res.push_back(0);
            res.push_back(1);
            return res;
        }

        vector<set<int>> m(n);
        for (auto &i : edges)
        {
            m[i[0]].insert(i[1]);
            m[i[1]].insert(i[0]);
        }
        //first set of leaf
        vector<int> cur;
        for (int i = 0; i < n; i++)
        {
            if (m[i].size() == 1)
                cur.push_back(i);
        }
        //BFS from leaf to center
        while (true)
        {
            vector<int> next;
            for (auto i : cur)
            {
                for (auto j : m[i])
                {
                    m[j].erase(i);
                    if (m[j].size() == 1)
                        next.push_back(j);
                }
            }
            if (next.empty())
                return cur;
            cur = next;
        }
    }
};
