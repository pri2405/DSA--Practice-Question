// Leetcode q no. - 1221

// 1st Approach - using two variable
class Solution {
public:
    int balancedStringSplit(string s) {   // T.C. - O(n) & S.C. - O(1)
        int n = s.length();
        int noOfR = 0;
        int noOfL = 0;
        int count = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == 'L') noOfL++;
            else noOfR++;

            if(noOfL == noOfR) {
                count++;
                noOfL = noOfR = 0;
            }
        }
        return count;
    }
};

// 2nd Approach  - using one variable
class Solution {
public:
    int balancedStringSplit(string s) {  // T.C. - O(n) & S.C. - O(1)
        int n = s.length();
        int balance = 0;
        int count = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == 'L') balance++;
            else balance--;

            if(!balance) count++;
        }
        return count;
    }
};