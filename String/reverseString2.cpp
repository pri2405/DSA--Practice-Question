// Leetcode q no. - 541

// Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

// 1st Approach
class Solution {
public:
    string reverseStr(string s, int k) {  
        int n = s.length();
        int idx = 0;
        while(idx < n) {
            if(idx + k < n) reverse(s.begin() + idx, s.begin() + idx + k);
            else {
                reverse(s.begin() + idx, s.end());
                return s;
            }
            idx += 2*k;
        }
        return s;
    }
};