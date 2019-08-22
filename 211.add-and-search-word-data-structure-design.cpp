/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 *
 * https://leetcode.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (29.84%)
 * Total Accepted:    110.7K
 * Total Submissions: 370.5K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addWord(word)
 * bool search(word)
 * 
 * 
 * search(word) can search a literal word or a regular expression string
 * containing only letters a-z or .. A . means it can represent any one
 * letter.
 * 
 * Example:
 * 
 * 
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * 
 * 
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 * 
 */
class WordDictionary
{
    struct TrieNode
    {
        TrieNode *ch[26];
        bool complete;
        TrieNode() : complete(false)
        {
            for (auto &i : ch)
            {
                i = nullptr;
            }
        }
    };
    class Trie
    {
      private:
        TrieNode *trie;

      public:
        Trie() : trie(new TrieNode()) {}
        void insert(string &s)
        {
            if (s.empty())
                return;
            auto it = trie;
            for (auto &c : s)
            {
                if (it->ch[c - 'a'] == nullptr)
                {
                    it->ch[c - 'a'] = new TrieNode();
                }
                it = it->ch[c - 'a'];
            }
            it->complete = true;
        }

        bool search(string &s)
        {
            cout << s << endl;
            vector<TrieNode *> v{trie};
            int pos = 0;
            while (!v.empty() && pos < s.size())
            {
                if (pos == s.size() - 1)
                {

                    if (s[pos] == '.')
                    {
                        for (auto i : v)
                        {
                            for (int k = 0; k < 26; k++)
                            {
                                if (i->ch[k] != nullptr && i->ch[k]->complete)
                                    return true;
                            }
                        }
                    }
                    else
                    {

                        for (auto i : v)
                        {
                            if (i->ch[s.back() - 'a'] != nullptr && i->ch[s.back() - 'a']->complete)
                                return true;
                        }
                    }
                }
                vector<TrieNode *> tmp;
                if (s[pos] == '.')
                {
                    for (auto i : v)
                    {
                        for (int j = 0; j < 26; j++)
                        {
                            if (i->ch[j] != nullptr)
                            {
                                tmp.push_back(i->ch[j]);
                            }
                        }
                    }
                }
                else
                {
                    for (auto i : v)
                    {
                        if (i->ch[s[pos] - 'a'] != nullptr)
                        {
                            tmp.push_back(i->ch[s[pos] - 'a']);
                        }
                    }
                }
                pos++;
                v = tmp;
            }
            return false;
        }
    };

    Trie tt;

  public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        tt.insert(word);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return tt.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
