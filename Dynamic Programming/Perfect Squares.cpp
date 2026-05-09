class Solution {
public:
    vector<int>v,dp;
    int n1;
    int solve(int rs){
        if(rs<0){
            return 1e9;
        }
        if(rs==0){
            return 0;
        }
        if(dp[rs]!=-1){
            return dp[rs];
        }
        int ans=1e9;
        for(int i=0;i<n1;i++){
            ans=min(ans,1+solve(rs-v[i]));
        }
        return dp[rs]=ans;
    }
    int numSquares(int n) {
        for(int i=1;i*i<=n;i++){
            v.push_back(i*i);
        }
        dp.assign(n+1,-1);
        n1=v.size();
        return solve(n);
    }
};