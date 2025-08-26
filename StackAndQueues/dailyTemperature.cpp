// Leetcode q no. - 739 (Daily Temperatures)

// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
// If there is no future day for which this is possible, keep answer[i] == 0 instead.

// 1st Approach   --  Brute Force Approach
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {      // T.C. - O(n^2) & S.C. - O(1)
        int n = temperatures.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n && !ans[i]; j++) {   // loop till next warmer day isnt found
                if(temperatures[j] > temperatures[i]) 
                    ans[i] = j - i;

            } 
        }
            
        return ans;
    }
};

// 2nd Approach  -  decreasing monotonic stack
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {      //T.C. - O(n) & S.C. - o(n)
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            while(st.size() && temperatures[i] > temperatures[st.top()]) {  
                ans[st.top()] = i - st.top();      
                st.pop();
            }
            st.push(i);                                
        }
        return ans;
    }
};

// 3rd Approach 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {    // T.C. - O(n) & s.C. - O(1)
        int n = temperatures.size();
        vector<int> ans(n);
        for(int i = n-2; i >= 0; i--) {
            int next = i + 1;                     
            while(next < n && temperatures[next] <= temperatures[i])       
                next += ans[next] ? ans[next] : n;  
            if(next < n) ans[i] = next - i;          
        }
        return ans;
    }
};
