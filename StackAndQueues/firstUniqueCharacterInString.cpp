// Leetcode q no. - 387   (First Unique Character in a string)

// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

// 1st Approach - Brute Force Approach
class Solution {
public:
    int firstUniqChar(string s) {       // T.C. - O(n^2) & S.C. - O(1)
        int n = s.length();
        for(int i=0; i<n; i++) {
            bool flag = true;
            for(int j=0; j<n; j++) {
                if(s[i] == s[j] && j != i) {
                    flag = false;
                    break;
                }
            }
            if(flag == true) return i;
        }
        return -1;
    }
};

// 2nd Approach  -  using hashing
class Solution {
public:
    int firstUniqChar(string s) {        //T.C. - O(n)  &  S.C. - O(n)
        unordered_map<char, int> mp;

        for(auto ch : s) {
            mp[ch]++;
        }

        for(int i=0; i<s.length(); i++) {
            if(mp[s[i]] == 1) return i;
        }
        return -1;
    }
};

// 3rd Approach - using hashing and queue
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        queue<int> q;

        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = 1;
                q.push(i);
            } else {
                mp[s[i]]++;
            }

            while (!q.empty() && mp[s[q.front()]] > 1) {
                q.pop();
            }
        }

        return q.empty() ? -1 : q.front();
    }
};