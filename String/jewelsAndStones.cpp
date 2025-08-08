//Leetcode q no. - 771

// You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.
// Letters are case sensitive, so "a" is considered a different type of stone from "A".

// 1st Approach - brute force approach (using nested loops)
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {  // T.C. - O(n1 * n2) & S.C. - O(1)
        int n1 = jewels.size();
        int n2 = stones.size();
        
        int count = 0;
        for(int i=0; i<n2; i++) {   // stones
            for(int j=0; j<n1; j++) {  // jewels
                if(stones[i] == jewels[j]) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};

// 2nd Approach  -- using hashing (unordered set)
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {  // T.C. - O(n1 + n2) & S.C. - O(n1)
        int n1 = jewels.size();
        int n2 = stones.size();
        
        unordered_set<char> st;
        for(int i=0; i<n1; i++) {
            st.insert(jewels[i]);
        }

        int count = 0;
        for(int i=0; i<n2; i++) {
            if(st.find(stones[i]) != st.end()) count++;
        }
        return count;
    }
};

// 3rd Approach  -  using built-in contains function
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int n = stones.size();
        int count = 0;
        for(int i=0; i<n; i++) {
            if(jewels.contains(stones[i])) count++;
        }
        return count;
    }
};