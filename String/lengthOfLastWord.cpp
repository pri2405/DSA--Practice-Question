// Leetcode q no. - 58

// Given a string s consisting of words and spaces, return the length of the last word in the string.
// A word is a maximal substring consisting of non-space characters only.

// 1st Approach  -  using one loop
class Solution {
public:
    int lengthOfLastWord(string s) {  // T.C. - O(n) & S.C. - O(1)
        int n = s.length();
        int count = 0;
        for(int i=n-1; i>=0; i--) {
            if(s[i] == ' ' && count == 0) continue;

            if(s[i] != ' ') count++;
            else break;
        }
        return count;
    }
};