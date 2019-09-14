/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;

        if (digits.empty())
            return res;

        vector<vector<char>> table(2, vector<char>());

        table.push_back(vector<char>{'a', 'b', 'c'}); // index 2
        table.push_back(vector<char>{'d', 'e', 'f'}); // 3
        table.push_back(vector<char>{'g', 'h', 'i'});
        table.push_back(vector<char>{'j', 'k', 'l'}); // 5
        table.push_back(vector<char>{'m', 'n', 'o'});
        table.push_back(vector<char>{'p', 'q', 'r', 's'}); // 7
        table.push_back(vector<char>{'t', 'u', 'v'});
        table.push_back(vector<char>{'w', 'x', 'y', 'z'}); // 9

        helper(0, table, "", res, digits);
        return res;
    }

    void helper(int pos, const vector<vector<char>> &table, const string &cur, vector<string> &res, const string &digits)
    {
        if (pos == digits.size())
        {
            res.emplace_back(cur);
        }
        else
        {
            for (auto i : table[digits[pos] - '0'])
            {
                auto tmp = cur;
                tmp += i;
                helper(pos + 1, table, tmp, res, digits);
            }
        }
    }
};
