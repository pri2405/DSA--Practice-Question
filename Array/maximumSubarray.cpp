// Leetcode q no. - 53

// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// 1st Approach - Brute Force Approach ---- It gives TLE
class Solution {
public:
    int maxSubArray(vector<int>& nums) {  // T.C. - O(n^2)  & S.C. - O(1)
        int n = nums.size();
        int maxSum = nums[0];
        for(int i=0; i<n; i++) {
            int sum = 0;
            for(int j=i; j<n; j++) {
                sum += nums[j];
                maxSum = max(sum, maxSum);
            }
        }
        return maxSum;
    }
};

// 2nd Approach - recursion
class Solution {
public:
    int solve(vector<int> &nums, int i, int currSum, int& maxSum) {
        if(i == nums.size()) return maxSum;

        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);

        return solve(nums, i+1, currSum, maxSum);
    }
    int maxSubArray(vector<int>& nums) {       // T.C. - O(n) and S.C. - O(n)
        int maxSum = nums[0];
        return solve(nums, 1, nums[0], maxSum);
    }
};

// 3rd Approach - Tabulation Method (DP)
class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {  // T.C. - O(n) & S.C. - O(n)
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int maxSum = nums[0];
        for(int i=1; i<n; i++) {
            if(dp[i-1] > 0) 
                dp[i] = nums[i] + dp[i-1];
            else dp[i] = nums[i];

            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};

// 4th Approach - Kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {  // T.C. - O(n) & S.C. - O(1)
        int n = nums.size();

        // Kadane's Algorithm
        int currSum = 0;
        int maxSum = nums[0];
        for(int i=0; i<n; i++) {
            currSum += nums[i];
            maxSum = max(currSum, maxSum);
            if(currSum < 0) currSum = 0;
        }
        return maxSum;
    }
};