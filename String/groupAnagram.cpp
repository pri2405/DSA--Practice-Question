// Leetcode q no. - 49

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// 1st Approach - using hashing and sorting
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {   // T.C. - O(m*n*logn) & S.C. - (m*n)
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(string str : strs) {
            string lexo = str;
            sort(lexo.begin(), lexo.end());
            mp[lexo].push_back(str);
        }
        for(auto x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};

// 2nd Approach - using hashing and frequency array
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for(string str : strs) {
            vector<int> temp(26,0);
            for(auto c : str)   temp[c-'a']++;

            string lexo = "" ;
            for (int j = 0; j < 26; j++) {
                if(temp[j]>0)
                    lexo += string(temp[j],j+'a');
            }
            mp[lexo].push_back(str);
        }
        for(auto x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};