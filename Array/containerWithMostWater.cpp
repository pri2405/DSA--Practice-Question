// Leetcode q no.- 11

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.

// 1st Approach - Brute Force Approach  --- It gives TLE
class Solution {
public:
    int maxArea(vector<int>& height) {   // T.C. - O(n^2) & S.C. - O(1)
        int n = height.size();
        int maxAmt = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int currAmt = (j-i) * min(height[i], height[j]);
                maxAmt = max(maxAmt, currAmt);
            }
        }
        return maxAmt;
    }
};

// 2nd Approach - two pointer approach
class Solution {
public:
    int maxArea(vector<int>& height) {  // T.C. - O(n) & S.C. - O(1)
        int left = 0;
        int right = height.size() - 1;
        int maxAmt = 0;
        while(left < right) {
            int currAmt = (right-left) * min(height[right], height[left]);
            maxAmt = max(maxAmt, currAmt);

            if(height[left] > height[right]) right--;
            else left++;
        }
        return maxAmt;
    }
};