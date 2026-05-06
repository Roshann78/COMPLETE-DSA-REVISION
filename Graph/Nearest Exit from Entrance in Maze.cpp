class Solution {
public:
    int n,m;
    bool check(int x,int y){
        return (x>=0 && y>=0 && x<n && y<m);
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        n=maze.size();
        m=maze[0].size();
        int arx[]={1,-1,0,0};
        int ary[]={0,0,1,-1};
        queue<vector<int>>q;
        q.push({0,entrance[0],entrance[1]});
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[entrance[0]][entrance[1]]=1;
        while(!q.empty()){
            auto v=q.front();
            q.pop();
            int dis=v[0],x=v[1],y=v[2];
            if((x==0 || y==0 || x==n-1 || y==m-1) && !(x==entrance[0] && y==entrance[1])){
                return dis;
            }
            for(int i=0;i<4;i++){
                int x1=x+arx[i];
                int y1=y+ary[i];
                if(!check(x1,y1) || maze[x1][y1]=='+' || vis[x1][y1]){
                    continue;
                }
                q.push({dis+1,x1,y1});
                vis[x1][y1]=1;
            }
        }
        return -1;
    }
};