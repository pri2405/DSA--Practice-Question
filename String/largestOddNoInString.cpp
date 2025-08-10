// Leetcode q no. - 1903

// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

// 1st Approach
class Solution {
public:
    string largestOddNumber(string num) {   // T.C. - O(n) & S.C. - O(1)
        int n = num.length();
        for(int i=n-1; i>=0; i--) {
            
            if((num[i] - '0') % 2 != 0) return num.substr(0, i+1);
        }
        return "";
    }
};