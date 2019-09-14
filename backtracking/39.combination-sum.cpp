/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
class Solution
{
public:
    // DFS
    // vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    // {
    //     vector<vector<int>> res;
    //     sort(candidates.begin(), candidates.end());
    //     helper(candidates, target, res, vector<int>{}, 0);
    //     return res;
    // }
    // void helper(vector<int> &candidates, int target, vector<vector<int>> &res, const vector<int> &cur, int pos)
    // {
    //     if (target == 0)
    //     {
    //         res.emplace_back(cur);
    //     }
    //     else
    //     {
    //         for (int i = pos; i < candidates.size(); i++)
    //         {
    //             if (target - candidates[i] < 0)
    //             {
    //                 break;
    //             }
    //             else
    //             {
    //                 auto tmp = cur;
    //                 tmp.push_back(candidates[i]);
    //                 helper(candidates, target - candidates[i], res, tmp, i);
    //             }
    //         }
    //     }
    // }

    // DP
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>());
        dp[0].push_back(vector<int>());
        for (auto candidate : candidates)
        {
            for (int i = candidate; i <= target; i++)
            {
                auto new_combinations = dp[i - candidate];
                for (auto &j : new_combinations)
                {
                    j.push_back(candidate);
                }
                dp[i].insert(dp[i].end(), new_combinations.begin(), new_combinations.end());
            }
        }
        return dp[target];
    }
};
