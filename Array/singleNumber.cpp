// Leetcode q no.- 136

// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// Approach - 1st  --> Brute Force Approach using nested loops
class Solution {
public:
    int singleNumber(vector<int>& nums) {     // T.C.- O(n^2)  and S.C.- O(1)
        int n = nums.size();
        
        for(int i=0; i<n; i++) {
            int ele = nums[i];
            int freq = 0;
            for(int j=0; j<n; j++) {
                if(ele == nums[j]) {
                    freq++;
                }
            }
            if(freq == 1) return ele;
        }
        
        return -1;
    }
};

// Approach -2nd  --> Better approach using unordered set (hashing)
class Solution {
public:
    int singleNumber(vector<int>& nums) {    // T.C.- O(n) and  S.C.- O(n)
        unordered_set<int> st;
        for(int i=0; i<nums.size(); i++) {
            if(st.find(nums[i]) == st.end())
                st.insert(nums[i]);
            else st.erase(nums[i]);
        }
        for(auto ele : st) return ele;     // only one element present in set
        return -1;
    }
};

// Approach -3rd  --> Better approach using unordered map (hashing)
class Solution {
public:
    int singleNumber(vector<int>& nums) {     // T.C.- O(n) and  S.C.- O(n)
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        for(auto ite : mp) {
            if(ite.second == 1) return ite.first;
        }
        return -1;
    }
};

// Approach - 4th  --> Optimised approach using bitwise XOR(^)
class Solution {
public:
    int singleNumber(vector<int>& nums) {    // T.C.- O(n)  and S.C.- O(1)
        int ans = 0;
        for(int ele : nums) ans = ans ^ ele;
        return ans;
    }
};