// Leetcode q no. - 131  (Palindrome Partitioning)

// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// T.C. - O(n * 2^n)  &  S.C. - O(n)
class Solution {
public:
    bool isPalindrome(string s, int x, int y) {
        for(int i = x; i <= (x+y)/2; i++){
            if(s[i] != s[x+y-i]) return false;
        }
        return true;
    }
    void rec(int idx, string s, vector<vector<string>> &ans, vector<string> &curr) {
        if(idx == s.length()) {
            ans.push_back(curr);
            return;
        }

        for(int i=idx; i<s.length(); i++) {
            if(isPalindrome(s, idx, i)) {
                curr.push_back(s.substr(idx, i-idx+1));
                rec(i+1, s, ans, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        rec(0, s, ans, curr);
        return ans;
    }
};