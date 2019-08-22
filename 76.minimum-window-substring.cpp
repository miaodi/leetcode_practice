/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
class Solution
{
public:
    string minWindow(string s, string t)
    {
        string res;
        if (s.empty() || t.empty())
            return res;
        unordered_map<char, int> m, w;
        for (const auto &i : t)
        {
            m[i]++;
        }
        int count = 0;
        int size = INT_MAX;
        for (int slow = 0, fast = 0; fast < s.size(); fast++)
        {
            if (m.count(s[fast]))
            {
                w[s[fast]]++;
                if (w[s[fast]] <= m[s[fast]])
                {
                    count++;
                }
            }
            if (count < t.size())
                continue;
            while (w.count(s[slow]) == 0 || w[s[slow]] > m[s[slow]])
            {
                if (w.count(s[slow]) != 0)
                {
                    w[s[slow]]--;
                }
                slow++;
            }
            if (size > fast - slow + 1)
            {
                size = fast - slow + 1;
                res = s.substr(slow, size);
            }
        }
        return res;
    }
};
