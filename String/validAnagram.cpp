// Leetcode q no. - 242

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// 1st Approach - using frequency array
class Solution {
public:
    bool isAnagram(string s, string t) {      // T.C. - O(n) & S.C. - O(1)
        if(s.length()!=t.length()) return false;
        int freqS[26];
        int freqT[26];

        for(int i=0; i<s.length(); i++) {
            freqS[s[i] - 97]++;
            freqT[t[i] - 97]++;
        }

        for(int i=0; i<26; i++) {
            if(freqS[i] != freqT[i]) return false;
        }
        return true;
    }
};

// 2nd Approach - by sorting
class Solution {
public:
    bool isAnagram(string s, string t) {  // T.C. - O(n*logn) & S.C. - O(1)
        if(s.length()!=t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return (s == t);
    }
};

// 3rd Approach - using hashing (unordered_map)
class Solution {
public:
    bool isAnagram(string s, string t) {    // T.C. - O(n) & S.C. - O(1) --- O(26) is constant
        if(s.length()!=t.length()) return false;
        unordered_map<char, int> map1;
        for(int i=0;i<s.length();i++){
            map1[s[i]]++;
        }
        for(int i=0; i<t.length(); i++){
            char ch = t[i];
            if(map1.find(ch)!=map1.end()){
                map1[ch]--;
                if(map1[ch]==0) map1.erase(ch);
            }
            else return false;
        }
        if(map1.size()>0) return false;
        return true;
    }
};