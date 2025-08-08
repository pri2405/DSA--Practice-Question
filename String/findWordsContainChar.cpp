// Leetcode q no. - 2942

// You are given a 0-indexed array of strings words and a character x.
// Return an array of indices representing the words that contain the character x.

// 1st method  - Brute force approach
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int n = words.size();
        for(int i=0; i<n; i++) {
            string word = words[i];
            
            for(int idx=0; idx<word.length(); idx++) {
                if(word[idx] == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};

// 2nd method  -- using built-in contains function
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int n = words.size();
        for(int i=0; i<n; i++) {
            if(words[i].contains(x)) ans.push_back(i);    
        }
        return ans;
    }
};