// Leetcode q no.- 268

// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

// 1st approach - Brute Force Approach(nested loops)
class Solution {
public:
    int missingNumber(vector<int>& nums) {  // T.C. - O(n^2) & S.C. - O(1)
        int n = nums.size();
        for(int i=0; i<=n; i++) {
            bool flag = false;   // doesn't present in array
            for(int j=0; j<n; j++) {
                if(nums[j] == i) {
                    flag = true;
                    break;
                }
            }
            if(flag == false) return i;
        }
        return -1;
    }
};

// 2nd Approach - by sorting
class Solution {
public:
    int missingNumber(vector<int>& nums) { // T.C.- O(n*logn) & S.C.-O(1)
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != i) return i;
        }
        return nums.size();
    }
};

//3rd Approach - by sorting and binary search
class Solution {
public:
    int missingNumber(vector<int>& nums) { // T.C.- O(n*logn) & S.C.-O(1)
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(nums[mid] > mid) right = mid;
            else left = mid+1;
        }
        return left;
    }
};

// 4th Approach  - total sum
class Solution {
public:
    int missingNumber(vector<int>& nums) {  // T.C. - O(n) & S.C.-O(1)
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }
        int total = n*(n+1) / 2;
        return total - sum;
    }
};

// 5th Approach - using XOR
class Solution {
public:
    int missingNumber(vector<int>& nums) {   //T.C.- O(n) & S.C.-O(1)
        int n = nums.size();
        int ans = n;
        for(int i=0; i<n; i++) {
            ans ^= i;
            ans ^= nums[i];
        }
        
        return ans;
    }
};
