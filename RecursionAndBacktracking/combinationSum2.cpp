// Leetcode q no. - 40 (combination sum 2)

// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// T.C. - O(2^n) & S.C. - O(n)
class Solution {
public:
    void helper(int idx, vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(v);
            return;
        }
        for(int i=idx; i<candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            v.push_back(candidates[i]);
            helper(i+1, candidates, target-candidates[i], v, ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> v;

        helper(0, candidates, target, v, ans);

        return ans;
    }
};