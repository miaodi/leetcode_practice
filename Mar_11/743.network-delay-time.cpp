/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 *
 * https://leetcode.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (40.30%)
 * Total Accepted:    26.4K
 * Total Submissions: 65.5K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * There are N network nodes, labelled 1 to N.
 * 
 * Given times, a list of travel times as directed edges times[i] = (u, v, w),
 * where u is the source node, v is the target node, and w is the time it takes
 * for a signal to travel from source to target.
 * 
 * Now, we send a signal from a certain node K. How long will it take for all
 * nodes to receive the signal? If it is impossible, return -1.
 * 
 * Note:
 * 
 * 
 * N will be in the range [1, 100].
 * K will be in the range [1, N].
 * The length of times will be in the range [1, 6000].
 * All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <=
 * 100.
 * 
 * 
 * 
 * 
 */
class Solution
{
  public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K)
    {
        vector<int> time(N, INT_MAX);
        time[K - 1] = 0;
        for (int i = 0; i < N; i++)
        {
            for (auto &i : times)
            {
                if (time[i[0] - 1] != INT_MAX && time[i[1] - 1] > time[i[0] - 1] + i[2])
                {
                    time[i[1] - 1] = time[i[0] - 1] + i[2];
                }
            }
        }
        int res = INT_MIN;
        for (auto i : time)
        {
            res = max(res, i);
        }
        return res == INT_MAX ? -1 : res;
    }
};
