#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // using Dynamic Programming (DP)
        int* dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
        
    }
};

int main()
{
    Solution S;
    cout<<"The answer is: "<<  S.climbStairs(4) << endl;
    return 0;
}