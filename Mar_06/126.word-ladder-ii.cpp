/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (17.03%)
 * Total Accepted:    110.9K
 * Total Submissions: 650.8K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * all shortest transformation sequence(s) from beginWord to endWord, such
 * that:
 * 
 * 
 * Only one letter can be changed at a time
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return an empty list if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: []
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */
class Solution
{
  public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> res;
        if (wordList.size() == 0)
            return res;
        unordered_map<string, vector<vector<string>>> q;
        q[beginWord].push_back(vector<string>{beginWord});
        while (q.size() != 0 && res.size() == 0)
        {
            unordered_map<string, vector<vector<string>>> tmp;
            vector<string> rem;
            for (auto &i : q)
            {
                for (auto it = wordList.begin(); it != wordList.end(); ++it)
                {
                    if (accept(i.first, *it))
                    {
                        for (auto k : i.second)
                        {
                            k.push_back(*it);
                            tmp[*it].push_back(k);
                            if (*it == endWord)
                                res.push_back(k);
                        }
                        rem.push_back(*it);
                    }
                }
            }

            for (auto &ii : rem)
            {
                wordList.erase(std::remove(wordList.begin(), wordList.end(), ii), wordList.end());
            }
            q = tmp;
        }
        return res;
    }
    bool accept(const string &l, const string &r)
    {
        int diff = 0;
        for (int i = 0; i < l.size(); i++)
        {
            if (l[i] != r[i])
            {
                diff++;
            }
        }
        return diff < 2;
    }
};
