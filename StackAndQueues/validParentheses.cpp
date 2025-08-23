// Leetcode q no. - 20  (Valid Parentheses)

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

//1st Approach - using stack
class Solution {
public:
    bool isValid(string s) {               // T.C. - O(n)  & S.C. - O(n)
        int n = s.size();

        if(n % 2 != 0) return false;
        
        stack<char> st;
        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else{
                if(st.size()==0) return false;
                if((s[i]==')' && st.top()=='(')||(s[i]=='}' && st.top()=='{')||(s[i]==']' && st.top()=='[')) 
                    st.pop();
                else return false;
            }
        }
        return (st.size()==0);
    }
};