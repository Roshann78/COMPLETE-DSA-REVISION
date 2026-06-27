class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();

        vector<vector<int>>ps=mat;

        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                ps[i][j]+=ps[i][j-1];
            }
        }

        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                ps[i][j]+=ps[i-1][j];
            }
        }

        vector<vector<int>>ans(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int l1=max(0,i-k),r1=max(0,j-k);
                int l2=min(n-1,i+k),r2=min(m-1,j+k);

                ans[i][j]=ps[l2][r2];
                if(l1){
                    ans[i][j]-=ps[l1-1][r2];
                }
                if(r1){
                    ans[i][j]-=ps[l2][r1-1];
                }

                if(l1 && r1){
                    ans[i][j]+=ps[l1-1][r1-1];
                }

            }
        }
        return ans;
    }
};