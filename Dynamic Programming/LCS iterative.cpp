class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,0));
        dp[0][0]=(s1[0]==s2[0]);
        for(int i=1;i<n2;i++){
            dp[0][i]=max((int)(s1[0]==s2[i]),dp[0][i-1]);
        }
        for(int i=1;i<n1;i++){
            dp[i][0]=max((int)(s1[i]==s2[0]),dp[i-1][0]);
        }
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(i==0 || j==0){
                    continue;
                }
                if(s1[i]==s2[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n1-1][n2-1];
    }
};