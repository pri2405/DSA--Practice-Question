// Leetcode q no. - 496  (Next Greater Element I)

// 1st Approach  -  Brute force approach
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {       // T.C. - O(m*n)  & S.C. - O(1)
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++) {       // size - m
            int nxt = -1;
            bool target = false;
            for(int j=0; j<nums2.size(); j++) {      // size - n
                if(nums2[j] == nums1[i]) target = true;
                else if(target == true) {
                    if(nums2[j] > nums1[i]) {
                        nxt = nums2[j];
                        break;
                    }
                }
            }
            ans.push_back(nxt);
        }
        return ans;
    }
};

// 2nd Approach - using hashing (unordered_map)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {   // T.C. - O(m+n)  & S.C. - O(m)
        unordered_map<int, int> ng;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                ng[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(ng.count(num) ? ng[num] : -1);
        }
        return ans;
    }
};