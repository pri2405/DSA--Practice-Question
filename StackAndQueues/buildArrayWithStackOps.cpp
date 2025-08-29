// Leetcode q no. - 1441  (Build an Array with Stack Operations)

// 1st Approach
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {        // T.C. - O(n)  & S.C.- O(1)
        int size = target.size();
        vector<string> ans;
        int val = 1;
        int idx = 0;
        while(val <= n && idx < size) {
            if(val == target[idx]) {
                ans.push_back("Push");
                idx++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            val++;
        }
        return ans;
    }
};