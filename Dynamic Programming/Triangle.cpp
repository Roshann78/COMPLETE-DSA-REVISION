class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n);
        dp[0].assign(1,triangle[0][0]);
        int ans=1e7;
        if(n==1){
            return triangle[0][0];
        }
        for(int i=1;i<n;i++){
            dp[i].assign(i+1,1e7);
            for(int j=0;j<i+1;j++){
                if(j<i){
                    dp[i][j]=dp[i-1][j]+triangle[i][j];
                }
                if(j-1>=0){
                    dp[i][j]=min(dp[i-1][j-1]+triangle[i][j],dp[i][j]);
                }
                if(i==n-1){
                    ans=min(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};