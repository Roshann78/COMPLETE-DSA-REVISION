class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        queue<vector<int>>q;
        int arx[]={1,-1,0,0};
        int ary[]={0,0,1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,i,j});
                }
            }
        }
        while(!q.empty()){
            auto v=q.front();
            int timer=v[0],x=v[1],y=v[2];
            ans=max(ans,timer);
            q.pop();
            for(int i=0;i<4;i++){
                int x1=x+arx[i],y1=y+ary[i];
                if(x1>=0 && y1>=0 && x1<n && y1<m && grid[x1][y1]==1){
                    grid[x1][y1]=2;
                    q.push({timer+1,x1,y1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};