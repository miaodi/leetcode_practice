/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */
class Solution
{
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> result;

public:
    void dfs(const string &vtex)
    {
        result.push_back(vtex);
        auto &edges = graph[vtex];
        if (edges.empty())
            return;
        string to_vtex = edges.top();
        edges.pop();
        dfs(to_vtex);
    }
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (auto e : tickets)
            graph[e[0]].push(e[1]);
        dfs("JFK");
        return result;
    }
};
