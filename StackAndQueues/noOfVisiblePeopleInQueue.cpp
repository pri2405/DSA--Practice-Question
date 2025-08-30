// Leetcode q no. - 1944

// 1st Approach - using monotonic stack
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {         // T.C. - O(n) & S.C. - O(n)
        int n = arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        st.push(arr[n-1]);
        ans[n-1] = 0;
        for(int i=n-2; i>=0; i--){
            int count = 0;
            //pop with ans
            while(st.size()>0 && arr[i]>st.top()){
                st.pop();
                count++;
            }
            if(st.size()!=0) count++; 
            ans[i] = count;
            st.push(arr[i]);
        }
        return ans;
    }
};