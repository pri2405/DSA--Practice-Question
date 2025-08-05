// Leetcode q no. - 75

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// 1st Approach - counting
class Solution {
public:
    void sortColors(vector<int>& nums) {  // T.C. - O(n) - two pass
        int n = nums.size();
        int noOf0s = 0;
        int noOf1s = 0;
        int noOf2s = 0;

        for(int i=0; i<n; i++) {
            if(nums[i] == 0) noOf0s++;
            else if(nums[i] == 1) noOf1s++;
            else noOf2s++;
        }


        for(int i=0; i<n; i++) {
            if(noOf0s != 0) {
                nums[i] = 0;
                noOf0s--;
            } else if(noOf1s != 0) {
                nums[i] = 1;
                noOf1s--;
            } else nums[i] = 2;
        }
    }
};

// 2nd Approach - Dutch National Flag Algorithm
class Solution {
public:
    void sortColors(vector<int>& nums) {  // T.C. - O(n) - One pass
        //one pass
    int low = 0;  //low
    int mid = 0;  //middle
    int high = nums.size()-1;  //high
    while(mid <= high ){
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid]==2){
            swap(nums[mid],nums[high]);
            high--;
        } 
        else mid++;
        
    }
        return;
    }
};