class Solution {
public:
    int lcs(string &s,int n1,int n2, vector<vector<int>> &dp)
    {
        if(n1>n2)
            return dp[n1][n2]=0;
        else if(n1==n2)
            return dp[n1][n2]=1;
        
        else if(dp[n1][n2]==-1)
        {
            if(s[n1]==s[n2])
            {
                dp[n1][n2]=2+lcs(s,n1+1,n2-1,dp);
            }
            else
            {
                dp[n1][n2]=max(lcs(s,n1+1,n2,dp),lcs(s,n1,n2-1,dp));
            }
        }
        return dp[n1][n2];
    }
    int longestPalindromeSubseq(string s) {
        
        if(s.size()==0)
            return 0;
        vector<vector<int>> dp(s.size(),vector<int> (s.size(),-1));
        return lcs(s,0,s.size()-1,dp);
    }
};