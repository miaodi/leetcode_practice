/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (30.42%)
 * Total Accepted:    330.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
// Too slow
class Solution
{
  public:
    bool isPalindrome(string s)
    {
        if (s.empty())
            true;
        for (auto it = s.begin(); it != s.end();)
        {
            if (*it>='A'&&*it<='Z'){
                *it=tolower(*it);
                it++;
            }else if((*it>='a'&&*it<='z')||(*it>='0'&&*it<='9')){
                it++;
            }else{
                it = s.erase(it);
            }
        }
        auto r = s;
        reverse(r.begin(), r.end()); 
        return r==s;
    }
};
