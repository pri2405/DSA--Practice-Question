// Leetcode q no. - 1021   (Remove Outermost Parentheses)

// 1st Approach - using stack
class Solution {
public:
    string removeOuterParentheses(string s) {          // T.C. - O(n)  &  S.C. - O(n)
        stack<int> st;
        string ans;

        for(auto i : s){
            if (i == '(') {
                if (st.size() > 0){
                    ans += '(';
                }
                st.push('(');
            } else {
                if(st.size() > 1){
                    ans += ')';
                }
                st.pop();
            }
            
        }
        return ans;
    }
};

// 2nd Approach - using constant space
class Solution {
public:
    string removeOuterParentheses(string s) {            // T.C. - O(n)  &  S.C. - O(1)
        string ans;
        int balance = 0;

        for(auto i : s){
            if (i == '(') {
                if (balance > 0){
                    ans += '(';
                }
                balance++;
            } else {
                if(balance > 1){
                    ans += ')';
                }
                balance--;
            }
            
        }
        return ans;
    }
};