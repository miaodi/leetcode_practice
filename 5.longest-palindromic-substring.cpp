/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() <= 1)
            return s;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int start, size;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; i + j < s.size(); j++)
            {
                dp[j][j + i] = (i <= 1 || dp[j + 1][j + i - 1]) && s[j] == s[j + i];
                if (dp[j][j + i])
                {
                    start = j;
                    size = i + 1;
                }
            }
        }
        return s.substr(start, size);
    }
};
