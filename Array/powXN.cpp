// Leetcode q no. - 50

// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

// 1st Approach - Brute Force
class Solution {
public:
    
    double myPow(double x, int n) {
        double ans = 1;
        long long pow = n;
        if(pow < 0) pow = -pow;
        for(long long i=1; i<=pow; i++) {
            ans *= x;
        }
        if(n < 0) return 1.0/ans;
        return ans;
    }
};

// 2nd Approach - recursive
class Solution {
public:
    double solve(double x, long n){  // T.C. - O(logn) & S.C. - O(logn)
        if(n == 0) return 1;
        if(n < 0) return solve(1/x, -n);
        if(n%2 == 0) return solve(x*x, n/2);
        else return x * solve(x*x, ((n-1)/2));
    }
    double myPow(double x, int n) {
        return solve(x, (long)n);
    }
};

// 3rd Approach  - Iterative
class Solution {
public:
    
    double myPow(double x, int n) {  // T.C. - O(logn) & S.C. - O(1)
        double ans = 1;
        long long pow = n;
        if(pow < 0) pow = -pow;
        while(pow > 0) {
            if(pow % 2 == 0) {
                x = x * x;
                pow /= 2;
            } else {
                ans *= x;
                pow--;
            }
        }
        if(n < 0) return 1.0/ans;

        return ans;
    }
};