// Leetcode q no. - 150 (Evaluate Reverse Polish Notation)


// 1st Approach - using stack
class Solution {
public:
    int evalRPN(vector<string>& tokens) {    // T.C. - O(n) & S.C. - O(n)
        int n = tokens.size();
        stack<int> st;

        for(auto ch : tokens) {
            if(ch=="+" || ch=="-" || ch=="*" || ch=="/") {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                if(ch == "+")  st.push(num1 + num2);
                else if(ch == "-")  st.push(num1 - num2);
                else if(ch == "*")  st.push(num1 * num2);
                else if(ch == "/")  st.push(num1 / num2);
            } else {
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};