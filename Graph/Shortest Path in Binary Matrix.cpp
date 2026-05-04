class Solution {
public:
    int n;
    bool check(int x1,int y1){
        return (x1>=0 && y1>=0 && x1<n && y1<n);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n=grid.size();
        if(grid[0][0]==1)return -1;
        int arx[]={1,1,1,-1,-1,-1,0,0};
        int ary[]={0,1,-1,0,1,-1,1,-1};
        queue<vector<int>>q;
        q.push({0,0,0});
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        while(!q.empty()){
            auto fr=q.front();
            q.pop();
            int dis=fr[0],x=fr[1],y=fr[2];
            if(x==n-1 && y==n-1){
                return dis+1;
            }
            for(int i=0;i<8;i++){
                int x1=x+arx[i],y1=y+ary[i];
                if(!check(x1,y1))continue;
                if(vis[x1][y1])continue;
                if(grid[x1][y1]==1)continue;
                q.push({dis+1,x1,y1});
                vis[x1][y1]++;
            }
        }
        return -1;
    }
};