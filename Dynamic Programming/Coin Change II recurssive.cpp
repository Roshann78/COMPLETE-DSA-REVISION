class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&coins,int n,int rem,int i){
        if(rem==0){
            return 1;
        }
        if(rem<0 || i>=n){
            return 0;
        }
        if(dp[rem][i]!=-1){
            return dp[rem][i];
        }
        int ans=0;
        ans+=solve(coins,n,rem,i+1);
        ans+=solve(coins,n,rem-coins[i],i);
        return dp[rem][i]=ans;
    }
    int change(int amount,vector<int>& coins) {
        int n=coins.size();
        dp.assign(amount+1,vector<int>(n,-1));
        return solve(coins,n,amount,0);
    }
};