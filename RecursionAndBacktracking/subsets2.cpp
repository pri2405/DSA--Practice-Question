// Leetcode q no. - 90 (Subsets II)

// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.


// 1st approach - 
class Solution {       // T.C. - O(2^n) & S.C. - O(n)
public:
    void rec(vector<int> &nums, vector<int>&v, int idx, vector<vector<int>> &ans){
        if(idx>=nums.size()){
            if(find(ans.begin(), ans.end(), v)==ans.end()){
                ans.push_back(v);
            }
            return;
        }
        v.push_back(nums[idx]);
        rec(nums,v,idx+1,ans);
        v.pop_back();
        rec(nums,v,idx+1,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        rec(nums,v,0,ans);

        return ans;
    }
};

// 2nd Approach
class Solution {
public:
    void recursive(int index,vector<int> & temp,vector<int>& nums,vector<vector<int>> & ans) {

        ans.push_back(temp);
        
        for(int i=index;i<nums.size();i++) {
            if(i!=index && nums[i]==nums[i-1]) continue;

            temp.push_back(nums[i]);
            recursive(i+1,temp,nums,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        recursive(0, v, nums, ans);

        return ans;
    }
};