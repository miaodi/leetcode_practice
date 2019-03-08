/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (51.00%)
 * Total Accepted:    304.7K
 * Total Submissions: 597.5K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */
class Solution
{
  public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> l, r;
        for (int i = 0; i < s.size(); i++)
        {
            l[s[i]]++;
            r[t[i]]++;
        }
        for(auto &i:l){
            auto j = r.find(i.first);
            if(j==r.end()||j->second!=i.second) return false;
        }
        return true;
    }
};
