// Leetcode q no. - 540

// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.

// Binary Search Approach
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {  // T.C. - O(logn) & S.C. - O(1)
        int n = nums.size();
        if(n==1) return nums[0];
        
        int start = 0;
        int end = n-1;
        while(start <= end) {
            int mid = start + (end - start)/2;

            if(mid == 0 && nums[0] != nums[1]) return nums[mid];
            if(mid == n-1 && nums[n-1] != nums[n-2]) return nums[mid];

            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];

            if(mid % 2 == 0) {
                if(nums[mid-1] == nums[mid]) end = mid - 1;
                else start = mid + 1;
            } else {
                if(nums[mid-1] == nums[mid]) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
};