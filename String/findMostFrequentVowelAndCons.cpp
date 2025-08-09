// Leetcode q no. - 3541

// 1st Approach - using frequency array
class Solution {
public:
    int maxFreqSum(string s) {   // T.C. - O(n) & S.C. - O(1)
        int n = s.length();
        int freq[26];

        for(int i=0; i<n; i++) {
            freq[s[i] - 'a']++;
        }

        int maxFreqVowel = 0;
        int maxFreqConsonant = 0;
        for(int i=0; i<26; i++) {
            if(i==0 || i==4 || i==8 || i==14 || i==20) 
                maxFreqVowel = max(maxFreqVowel, freq[i]);
            else 
                maxFreqConsonant = max(maxFreqConsonant, freq[i]);
        }
        return maxFreqVowel + maxFreqConsonant;
    }
};

// 2nd Approach - using Hashing (unordered_map)
class Solution {
public:
    int maxFreqSum(string s) {  // T.C. - O(n) & S.C. - O(1) --- max space used by map is 26(constant)
        int n = s.length();
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++) {
            mp[s[i]]++;
        }
        int maxFreqVowel = 0;
        int maxFreqConsonant = 0;
        for(auto it : mp) {
            string vowel = "aeiou";
            if(vowel.contains(it.first)) maxFreqVowel = max(maxFreqVowel, it.second);
            else maxFreqConsonant = max(maxFreqConsonant, it.second);
        }
        return maxFreqVowel + maxFreqConsonant;
    }
};