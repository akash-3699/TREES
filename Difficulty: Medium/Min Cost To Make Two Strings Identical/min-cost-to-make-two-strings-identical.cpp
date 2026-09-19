class Solution {
  public:
    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        // code here
         int n = s1.size(), m = s2.size();
        
        // dp[i][j] = length of LCS of s1[0..i-1] and s2[0..j-1]
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int lcs = dp[n][m];
        int deletedFromS1 = n - lcs;
        int deletedFromS2 = m - lcs;
        
        return deletedFromS1 * costS1 + deletedFromS2 * costS2;
    }
};