// Leetcode q no.- 121

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// 1st Approach - using nested loops
// this solution gives TLE
class Solution {
public:
    int maxProfit(vector<int>& prices) {   // T.C. - O(n^2) &  S.C. - O(1)
        int n = prices.size();
        int maxProfit = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(prices[i] < prices[j]) 
                    maxProfit = max(maxProfit, prices[j]-prices[i]);
            }
        }
        return maxProfit;
    }
};

// 2nd Approach - Tabulation Method
class Solution {
public:
    int maxProfit(vector<int>& prices) {    // T.C. - O(n)  &  S.C.- O(n)
        int n = prices.size();
        vector<int> maxPrices(n, 0);
        maxPrices[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--) {
            maxPrices[i] = max(maxPrices[i+1], prices[i]);
        }

        int maxProfit = 0;
        for(int i=0; i<n; i++) {
            maxProfit = max(maxProfit, maxPrices[i]-prices[i]);
        }
        return maxProfit;
    }
};

// 3rd approach - Optimized approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {   // T.C.- O(n)  &  S.C. - O(1)
        int n = prices.size();
        int maxProfit = 0;
        int buy = prices[0];
        for(int i=1; i<n; i++) {
            buy = min(buy, prices[i]);

            maxProfit = max(maxProfit, prices[i] - buy);
        }
        return maxProfit;
    }
};