// Leetcode q no. - 1910

// 1st Approach - Brute force Approach
class Solution {
public:
    string removeOccurrences(string s, string part) {          // T.C. - O(n*m) & S.C. - O(n)
        while(s.length() > 0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

// 2nd Approach - stack approach
class Solution {
public:
    string removeOccurrences(string s, string part) {       // T.C. - O(n) & S.C. - O(n)
        string ans;
        int targetLength = part.size();
        char targetEndChar = part.back();

        for(char ch : s) {
            ans.push_back(ch);

            if(ch == targetEndChar && ans.size() >= targetLength) {
                if(ans.substr(ans.size() - targetLength) == part) {
                    ans.erase(ans.size() - targetLength);
                }
            }
        }
        return ans;
    }
};

// 3rd Approach  - Knuth-Morris-Pratt (KMP) Algorithm
class Solution {
    // this function return the computed longest prefix-suffix array
    vector<int> helper(string pattern) {
        vector<int> lps(pattern.length(), 0);

        for(int curr = 1, prefixLength = 0; curr < pattern.length();) {
            if(pattern[curr] == pattern[prefixLength]) {
                lps[curr] = ++prefixLength;
                curr++;
            }
            else if(prefixLength != 0) {
                prefixLength = lps[prefixLength - 1];
            }
            else {
                lps[curr] = 0;
                curr++;
            }
        }
        return lps;
    }
public:
    string removeOccurrences(string s, string part) {
        vector<int> v = helper(part);
        stack<char> st;
        vector<int> patternIdxs(s.length() + 1, 0);

        for(int strIdx=0, ptrnIdx=0; strIdx < s.length(); strIdx++) {
            char currChar = s[strIdx];
            st.push(currChar);

            if(currChar == part[ptrnIdx]) {
                patternIdxs[st.size()] = ++ptrnIdx;

                if(ptrnIdx == part.length()) {
                    int len = part.length();
                    while(len != 0) {
                        st.pop();
                        len--;
                    }
                    ptrnIdx = st.empty() ? 0 : patternIdxs[st.size()];
                }
            } else {
                if(ptrnIdx != 0) {
                    strIdx--;
                    ptrnIdx = v[ptrnIdx - 1];
                    st.pop();
                } else {
                    patternIdxs[st.size()] = 0;
                }
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
