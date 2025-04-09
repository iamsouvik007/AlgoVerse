// C++ Solutions for Climbing Stairs Problem
// Includes: Pure Recursion with Memoization, Iterative DP, and Space Optimized DP
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // Memoization array to store intermediate results
        int memo[46];
    
        // Recursive function with memoization
        int solve(int n) {
            if (n < 0) return 0;
            if (n == 0) return 1;
            if (memo[n] != -1) return memo[n];
    
            return memo[n] = solve(n - 1) + solve(n - 2);
        }
    
        // Entry function for recursive + memoized solution
        int climbStairsMemo(int n) {
            memset(memo, -1, sizeof(memo));
            return solve(n);
        }
    
        // Iterative DP with vector (bottom-up approach)
        int climbStairsDP(int n) {
            if (n == 1 || n == 2 || n == 3) return n;
            vector<int> arr(n + 1);
            arr[0] = 0;
            arr[1] = 1;
            arr[2] = 2;
    
            for (int i = 3; i <= n; i++) {
                arr[i] = arr[i - 1] + arr[i - 2];
            }
            return arr[n];
        }
    
        // Optimized space solution using 2 variables
        int climbStairsOptimized(int n) {
            if (n == 1 || n == 2 || n == 3) return n;
            int a = 1, b = 2, c;
    
            for (int i = 3; i <= n; i++) {
                c = a + b;
                a = b;
                b = c;
            }
            return b;
        }
    };

int main(){

}