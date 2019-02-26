/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (39.08%)
 * Total Accepted:    220.4K
 * Total Submissions: 564.1K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */
// permutation algorithm should be understand.
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> m;

        helper(m, nums, 0);

        vector<vector<int>> res;
        for(auto &i:m){
            res.push_back(i);
        }
        return res;
    }
    void helper (set<vector<int>>& m,vector<int>& num, int digit){
        if(digit==num.size()){
            m.insert(num);
        }else{
            for(int i=digit;i<num.size();i++){
                swap(num[digit], num[i]);
                helper(m, num, digit+1);
                swap(num[digit], num[i]);//this operation is important, recover the original vector.
            }
        }
    }
};

