// Leetcode q no. - 14

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// 1st Approach - Brute Force approach
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for(int i = 0 ; i < strs[0].size() ; i++){
            char ch = strs[0][i]; 
            bool flag = true ;
            for(int j = 0 ; j < strs.size() ; j++){
                if(strs[j][i] != ch)
                    flag = false;
            }
            if(flag) ans += ch ;
            else break ; 
        } 
        return ans ;
    }
};

// 2nd Approach - by sorting(& check prefix of first element and last element)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {  // T.C. - O(n*logn) & S.C. - O(1)
        string ans = "";
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string firstEle = strs[0];
        string lastEle = strs[n-1];
        for(int i=0; i<min(firstEle.size(),lastEle.size()); i++){
            if(firstEle[i]!=lastEle[i]) return ans;
            else ans += firstEle[i];
        }
        return ans;
    }
};