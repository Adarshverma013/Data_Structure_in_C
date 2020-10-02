class Solution {
public:
    int lcs(string str1,string str2,int n1,int n2,vector<vector<int>> &dp)
    {
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
    string plcs(string str1,string str2,int n1,int n2,vector<vector<int>> dp)
    {
        string ans = "";
        int i = n1,j = n2;
    
        while(j > 0 && i > 0)
        {
            if(str1[i-1] == str2[j-1])
            {
                ans += str1[i-1];
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j] > dp[i][j-1])
                {
                    ans += str1[i-1];
                    i--;
                }
                else
                {
                    ans += str2[j-1];
                    j--;
                }
            }
        }
        while(j > 0)
        {
            ans += str2[j-1];
            j--;
        }
        while(i > 0)
        {
            ans += str1[i-1];
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.size();
        int n2=str2.size();
        
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
        int len=lcs(str1,str2,n1,n2,dp);
        return plcs(str1,str2,n1,n2,dp);
     }
};