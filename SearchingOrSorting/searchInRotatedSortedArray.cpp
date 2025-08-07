// leetcode q no. - 33

// Binary Search approach
class Solution {
public:
    int search(vector<int>& nums, int target) { // T.C. - O(logn) & S.C. - O(1)
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end) {
            int mid = start + (end - start)/2;
            if(nums[mid] == target) return mid;

            if(nums[start] <= nums[mid]) {  // left part sorted
                if(nums[start] <= target && target <= nums[mid]) end = mid - 1;
                else start = mid + 1;
            } else {     // right part sorted
                if(nums[mid] <= target && target <= nums[end]) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;

    }
};