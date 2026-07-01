class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>adj1(n,vector<int>(m)),adj2(n,vector<int>(m));

        int p=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                adj1[i][j]=(1LL*p*grid[i][j])%12345;
                p=adj1[i][j];
            }
        }

        p=1;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                adj2[i][j]=(1LL*p*grid[i][j])%12345;
                p=adj2[i][j];
            }
        }

        vector<vector<int>>ans(n,vector<int>(m));
        if(n==1 && m==1){
            return grid;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!i && !j){
                    if(m>1){
                        ans[i][j]=adj2[0][1];
                    }else{
                        ans[i][j]=adj2[1][0];
                    }
                    continue;
                }
                if(i==n-1 && j==m-1){
                    if(m>1){
                        ans[i][j]=adj1[n-1][m-2];
                    }else{
                        ans[i][j]=adj1[i-1][0];
                    }
                    continue;
                }
                if(!j){
                    if(m>1){
                        ans[i][j]=(adj1[i-1][m-1]*adj2[i][j+1])%12345;
                    }else{
                        ans[i][j]=(adj1[i-1][0]*adj2[i+1][0])%12345;
                    }
                    continue;
                }
                if(j==m-1){
                    ans[i][j]=(adj1[i][j-1]*adj2[i+1][0])%12345;
                    continue;
                }
                ans[i][j]=(adj1[i][j-1]*adj2[i][j+1])%12345;
            }
        }
        return ans;
    }
};