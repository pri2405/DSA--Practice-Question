// Leetcode q no. - 26

// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {   // two pointer approach
        int n = nums.size();
        if(n==1) return 1;
        int idx = 1;
        for(int i=0; i<n-1; i++){
            if(nums[i] != nums[i+1]) {
                nums[idx] = nums[i+1];
                idx++;
            }
        }
        return idx;
    }
};

