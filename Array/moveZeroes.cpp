//Leetcode q no. - 283

// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements

//  1st Approach  -  using extra space
class Solution {
public:
    void moveZeroes(vector<int>& nums) {  // T.C. - O(n) & S.C. - O(n)
        int n = nums.size();
        vector<int> ans(nums.begin(), nums.end());
        int idx = 0;
        // fill the ans array with non-zero elements
        for(int i=0; i<n; i++) {
            if(ans[i] != 0) nums[idx++] = ans[i];
        }
        while(idx < n) {
            nums[idx++] = 0;
        }
        
    }
};

// 2nd Approach - optimized approach using two pointer
class Solution {
public:
    void moveZeroes(vector<int>& nums) {  // T.C. - O(n) & S.C. - O(1)
        int n = nums.size();
        int idx = 0;
        for(int i=0; i<n; i++){ // fill non-zero element
            if(nums[i] != 0) nums[idx++] = nums[i];
        }
        //fill zeroes
        while(idx < n) {
            nums[idx++] = 0;
        }
    }
}; 