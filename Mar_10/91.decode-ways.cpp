/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (21.82%)
 * Total Accepted:    235.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 *
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 *
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 *
 * Example 1:
 *
 *
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 *
 *
 * Example 2:
 *
 *
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 *
 */
class Solution
{
  public:
    int numDecodings(string s)
    {
        vector<int> s1(s.size(), 0), s2(s.size(), 0);
        if (s.size() == 0 || s[0] == '0')
            return 0;
        s1[0] = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '0' && (s[i - 1] == '1' || s[i - 1] == '2'))
            {
                s2[i] = s1[i - 1];
                s1[i] = 0;
                continue;
            }
            else if (s[i] == '0' && (s[i - 1] != '1' && s[i - 1] != '2'))
            {
                return 0;
            }// This problem may provide you some numbers that can't be decoded.

            if (s[i - 1] == '1')
            {
                s1[i] = s1[i - 1] + s2[i - 1];
                s2[i] = s1[i - 1];
                continue;
            }
            if (s[i - 1] == '2' && s[i] != '7' && s[i] != '8' && s[i] != '9')
            {
                s1[i] = s1[i - 1] + s2[i - 1];
                s2[i] = s1[i - 1];
                continue;
            }
            {
                s1[i] = s1[i - 1] + s2[i - 1];
                s2[i] = 0;
                continue;
            }
        }
        return s1.back() + s2.back();
    }
};
