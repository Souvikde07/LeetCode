class Solution {
public:

    int f(int num, int lastcp, int tar, vector<vector<int>> &dp) {
    if (num == tar) return 0;
    if (num + lastcp > tar) return 2000;
    
    if (dp[num][lastcp] != -1) return dp[num][lastcp];
    int cp = 2 + f(num + num, num, tar, dp);
    int p = 1 + f(num + lastcp, lastcp, tar, dp);

    return dp[num][lastcp] = min(cp, p);
    }

    int minSteps(int n) {
        if (n == 1) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        return f(2, 1, n, dp) + 2;
    }

};