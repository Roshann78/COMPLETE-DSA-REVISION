class Solution {
public:
    vector<vector<int>>dp;
    int n1,n2;
    int solve(int i,int j,string &word1,string &word2){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j]=solve(i-1,j-1,word1,word2);
        }
        return dp[i][j]=min(1+solve(i,j-1,word1,word2),1+solve(i-1,j,word1,word2));
    }
    int minDistance(string word1, string word2) {
        n1=word1.size(),n2=word2.size();
        dp.assign(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,word1,word2);
    }
};