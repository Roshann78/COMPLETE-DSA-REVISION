class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,1e5));
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({0,i,j});
                }
            }
        }
        int arx[]={1,-1,0,0};
        int ary[]={0,0,1,-1};
        while(!q.empty()){
            auto v=q.front();
            int dis=v[0],x=v[1],y=v[2];
            q.pop();
            for(int i=0;i<4;i++){
                int x1=x+arx[i],y1=y+ary[i];
                if(x1>=0 && y1>=0 && x1<n && y1<m && ans[x1][y1]>dis+1){
                    ans[x1][y1]=dis+1;
                    q.push({dis+1,x1,y1});
                }
            }
        }
        return ans;
    }
};