/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (46.88%)
 * Total Accepted:    71.3K
 * Total Submissions: 152K
 * Testcase Example:  '[ ["a","b"],["b","c"] ]\n[2.0,3.0]\n[
 * ["a","c"],["b","c"],["a","e"],["a","a"],["x","x"] ]'
 *
 *
 * Equations are given in the format A / B = k, where  A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 *
 * Example:
 * Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e
 * = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 *
 *
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 *
 *
 * According to the example above:
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ].
 *
 *
 *
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 *
 */

// DFS
class Solution
{
  public:
    vector<double> calcEquation(vector<pair<string, string>> equations,
                                vector<double> &values,
                                vector<pair<string, string>> queries)
    {
        vector<double> res;
        for (auto &i : queries)
        {
            double re = 1.0;
            if (divide(equations, values, i, re))
            {
                res.push_back(re);
            }
            else
            {
                res.push_back(-1.0);
            }
        }
        return res;
    }
    bool divide(vector<pair<string, string>> &equations, vector<double> &values,
                pair<string, string> &div, double &res)
    {
        for (int i = 0; i < equations.size(); i++)
        {
            if (equations[i].first == div.first)
            {
                if (div.first == div.second)
                    return true;
                auto tmp = res * values[i];
                if (equations[i].second == div.second)
                {
                    res = tmp;
                    return true;
                }
                else
                {
                    auto tmp_div = div;
                    tmp_div.first = equations[i].second;
                    auto first = equations[i].first;
                    auto second = equations[i].second;
                    equations[i].first = "nig";
                    equations[i].second = "nig";
                    if (divide(equations, values, tmp_div, tmp))
                    {
                        res = tmp;
                        equations[i].first = first;// Important
                        equations[i].second = second;// Important
                        return true;
                    }
                    equations[i].first = first;
                    equations[i].second = second;
                }
            }
            else if (equations[i].second == div.first)
            {
                if (div.first == div.second)
                    return true;
                auto tmp = res / values[i];
                if (equations[i].first == div.second)
                {
                    res = tmp;
                    return true;
                }
                else
                {
                    auto tmp_div = div;
                    tmp_div.first = equations[i].first;
                    auto first = equations[i].first;
                    auto second = equations[i].second;
                    equations[i].first = "nig";
                    equations[i].second = "nig";
                    if (divide(equations, values, tmp_div, tmp))
                    {
                        res = tmp;
                        equations[i].first = first;
                        equations[i].second = second;
                        return true;
                    }
                    equations[i].first = first;
                    equations[i].second = second;
                }
            }
        }
        return false;
    }
};
