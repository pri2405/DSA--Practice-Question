// Leetcode q no. - 344

// Write a function that reverses a string. The input string is given as an array of characters s.

// 1st Approach - using stack
class Solution {
public:
    void reverseString(vector<char>& s) {    // T.C. - O(n) & S.C. - O(n)
        stack<char> st;
        for(int i=0; i<s.size(); i++) {
            st.push(s[i]);
        }
        int idx = 0;
        while(!st.empty()) {
            s[idx++] = st.top();
            st.pop();
        }
    }
};

// 2nd Approach - two pointer approach
class Solution {
public:
    void reverseString(vector<char>& s) {   // T.C. - O(n) & S.C. - O(1)
        int left = 0;
        int right = s.size() - 1;
        while(left < right) {
            swap(s[left++], s[right--]); 
        }
    }
};

// 3rd Approach - using recursion
class Solution {
    void reverse(vector<char> &s, int left, int right) {
        if(left >= right) return;
        swap(s[left], s[right]);
        reverse(s, left+1, right-1);
    }
public:
    void reverseString(vector<char>& s) {
        reverse(s, 0, s.size() - 1);
    }
};