// Leetcode q no. - 169

// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array

// 1st Approach - Brute Force Approach
class Solution {
public:
    int majorityElement(vector<int>& nums) {  // T.C. - O(n^2) & S.C. - O(1)
        int n = nums.size();
        for(int i=0; i<n; i++) {
            int freq = 0;
            for(int j=0; j<n; j++) {
                if(nums[i] == nums[j]) freq++;
            }
            if(freq > n/2) return nums[i];
        }
        return -1;
    }
};

// 2nd Approach - By sorting
class Solution {
public:
    int majorityElement(vector<int>& nums) {  // T.C. - O(n*logn) & S.C. - O(1)
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int freq = 1;
        for(int i=1; i<n; i++) {
            if(nums[i-1] == nums[i]) freq++;
            else {
                freq = 1;
            }
            if(freq > n/2) return nums[i];
        }
        return nums[0];
    }
};

// 3rd Approach - Using Hashmap
class Solution {
public:
    int majorityElement(vector<int>& nums) {   // T.C. - O(n) & S.C. - O(n)
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
        }

        for(auto it : mp) {
            if(it.second > n/2) return it.first;
        }
        return -1;
    }
};

// 4th Approach - Moore Voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {    // T.C. - O(n)  & S.C. - O(1)
        int n = nums.size();
        int freq = 1;
        int ele = nums[0];
        for(int i=1; i<n; i++) {
            if(freq == 0) ele = nums[i];

            if(nums[i] == ele) freq++;
            else freq--;
        }
        return ele;
    }
};