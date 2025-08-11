// Leetcode q no. - 205

// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// 1st Approach - using hashing (unordered_map & unordered_set both)
class Solution {
public:
    bool isIsomorphic(string s, string t) {        // T.C. - O(n) & S.C. - O(1) ~ O(256) is constant
        if(s.length() != t.length()) return false;

        unordered_map<char, char> mp;   // stores mapping characters
        unordered_set<char> st;        
        for(int i=0; i<s.length(); i++) {
            if(mp.find(s[i]) == mp.end() && st.find(t[i]) != st.end()) return false; //two diff. char mapped to same char. -- return false;
            else st.insert(t[i]);

            if(mp.empty() || mp.find(s[i]) == mp.end() )  mp[s[i]] = t[i];

            else if(mp.find(s[i]) != mp.end() && mp[s[i]] != t[i]) return false; 
        }
        return true;
    }
};

// 2nd Approach - using one hashmap 
class Solution {
public:
    bool helper(string s, string t) {          // T.C. - O(n) & S.C. - O(1)
        unordered_map<char, char> mp;
        for(int i=0; i<s.length(); i++) {
            if(mp.find(s[i]) != mp.end()) {
                if(mp[s[i]] != t[i]) return false;
            }
            else mp[s[i]] = t[i];
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return helper(s, t) && helper(t , s);
    }
};