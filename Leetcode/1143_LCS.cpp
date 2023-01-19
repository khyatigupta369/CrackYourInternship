class Solution
{
private:
    int solve(int i1, int i2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i1 < 0 || i2 < 0)
            return 0;
        if (dp[i1][i2] != -1)
            return dp[i1][i2];
        if (s1[i1] == s2[i2])
        {
            return dp[i1][i2] = 1 + solve(i1 - 1, i2 - 1, s1, s2, dp);
        }
        else
        {
            return dp[i1][i2] = max(solve(i1 - 1, i2, s1, s2, dp), solve(i1, i2 - 1, s1, s2, dp));
        }
    }

public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, s1, s2, dp);
    }
};