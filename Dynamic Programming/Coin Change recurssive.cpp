class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&coins,int n,int rem){
        if(rem==0){
            return 0;
        }
        if(rem<0){
            return 1e9;
        }
        if(dp[rem]!=-1){
            return dp[rem];
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            ans=min(ans,1+solve(coins,n,rem-coins[i]));
        }
        return dp[rem]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.assign(amount+1,-1);
        int ans=solve(coins,n,amount);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};