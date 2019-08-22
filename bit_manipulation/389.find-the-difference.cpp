/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */
class Solution
{
public:
    // 136. Single Number (https://leetcode.com/problems/single-number/)
    char findTheDifference(string s, string t)
    {
        char res = 0;
        for (char c : s)
            res ^= c;
        for (char c : t)
            res ^= c;
        return res;
    }
};
