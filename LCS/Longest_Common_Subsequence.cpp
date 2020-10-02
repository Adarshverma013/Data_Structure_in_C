class Solution {
public:
    int helper(string &A,string &B,int n,int m,vector<vector<int>> &dp)
    {
        if(n==A.size()||m==B.size())
        return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(A[n]==B[m])
        dp[n][m]=1+helper(A,B,n+1,m+1,dp);
        else
        dp[n][m]=max(helper(A,B,n+1,m,dp),helper(A,B,n,m+1,dp));
                     
        return dp[n][m];
    }
    int longestCommonSubsequence(string A, string B) {
        vector<vector<int>> dp(A.size(),vector<int> (B.size(),-1));
        return helper(A,B,0,0,dp);
    }
};