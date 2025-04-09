// 1. Top-Down DP (Memoization) — Recursive + Cache
// Time Complexity: O(n), due to memoization caching each subproblem
// Space Complexity: O(n), for recursion stack + dp array
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        // Helper function to compute nth Fibonacci using recursion and memoization
        int solve(int n, vector<int>& dp) {
            if (n <= 1) return n;  // Base case: fib(0) = 0, fib(1) = 1
    
            if (dp[n] != -1) return dp[n];  // Return cached result if available
    
            // Recursively compute and cache result
            return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
        }
    
        int fib(int n) {
            if (n <= 1) return n;
            vector<int> dp(n + 1, -1);  // Initialize memoization table with -1
            return solve(n, dp);
        }
    };
    
    
    // 2. Bottom-Up DP (Tabulation) — Iterative + Table
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    
    class Solution {
    public:
        int fib(int n) {
            if (n <= 1) return n;  // Base case
            vector<int> dp(n + 1, 0);  // Create DP table and initialize
    
            dp[0] = 0;  // fib(0)
            dp[1] = 1;  // fib(1)
    
            // Fill the DP table from bottom up
            for (int i = 2; i <= n; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
    
            return dp[n];  // Final result
        }
    };
    
    
    // 3. Bottom-Up DP (Space Optimized) — Iterative + Constant Space
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    
    class Solution {
    public:
        int fib(int n) {
            if (n <= 1) return n;  // Base case
    
            int a = 0, b = 1, c = 0;
    
            // Only store last two values to compute next one
            for (int i = 2; i <= n; i++) {
                c = a + b;
                a = b;
                b = c;
            }
    
            return b;  // Final result
        }
    };
    

int main(){
    
}