// Leetcode q no. - 485

// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// 1st Approach
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {  // T.C. - O(n) & S.C. - O(1)
        int n = nums.size();
        int ans = 0;
        int count = 0;   
        for(int i=0; i<n; i++) {
            if(nums[i] == 1) count++;
            else {
                ans = max(ans, count);
                count = 0;
            }
        }
        ans = max(ans, count);
        return ans;
    }
};