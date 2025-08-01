// Leetcode q no. - 27

// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {   // two pointer approach
        int n = nums.size();
        int idx = 0;   // used to store element not equal to val
        for(int i=0; i<n; i++) {
            if(nums[i] != val) {
                nums[idx] = nums[i];
                idx++;
            }
        }
        return idx;
    }
};