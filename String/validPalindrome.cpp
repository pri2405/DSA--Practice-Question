// Leetcode q no. - 1903

// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

// Two pointer approach
class Solution {
public:
    bool isAlphaNum(char ch) {
        if(ch >= 'a' && ch <='z' ||
             ch >='A' && ch <= 'Z'  ||
                ch >= '0' && ch <='9') return true;

        return false;
    }
    bool isPalindrome(string s) {  // T.C. - O(n) & S.C. - O(1)
        int st = 0;
        int end = s.length() - 1;
        while(st < end) {
            while(st < end && !isAlphaNum(s[st])) {
                st++;
            }
            while(st < end && !isAlphaNum(s[end])) {
                end--;
            }
            if(tolower(s[st]) != tolower(s[end])) return false;
            st++;
            end--;
        }
        return true;
    }
};