/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 *
 * https://leetcode.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Hard (32.11%)
 * Total Accepted:    54.1K
 * Total Submissions: 168.5K
 * Testcase Example:  '"bcabc"'
 *
 * Given a string which contains only lowercase letters, remove duplicate
 * letters so that every letter appear once and only once. You must make sure
 * your result is the smallest in lexicographical order among all possible
 * results.
 *
 * Example 1:
 *
 *
 * Input: "bcabc"
 * Output: "abc"
 *
 *
 * Example 2:
 *
 *
 * Input: "cbacdcbc"
 * Output: "acdb"
 *
 */
class Solution
{
  public:
    string removeDuplicateLetters(string s)
    {
        vector<int> visited(26, 0), count(26, 0);
        for (auto i : s)
        {
            count[i - 'a']++;
        }
        string res = "";
        for (auto i : s)
        {
            if (visited[i - 'a'] == 0)
            {
                while (!res.empty() && res.back() > i && count[res.back() - 'a'] > 0)
                {
                    visited[res.back() - 'a'] = 0;
                    res.pop_back();
                }
                res += i;
                visited[i - 'a'] = 1;
            }
            count[i - 'a']--;
        }
        return res;
    }
};
