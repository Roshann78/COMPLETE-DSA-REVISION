class Solution {
public:
    bool check(vector<vector<int>>& heights,int mid){
        int n=heights.size(),m=heights[0].size();
        int arx[]={1,-1,0,0};
        int ary[]={0,0,1,-1};
        queue<vector<int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        q.push({0,0});
        while(!q.empty()){
            auto v=q.front();
            int x=v[0],y=v[1];
            if(x==n-1 && y==m-1){
                return true;
            }
            q.pop();
            for(int i=0;i<4;i++){
                int x1=x+arx[i],y1=y+ary[i];
                if(x1>=0 && y1>=0 && x1<n && y1<m && !vis[x1][y1] && heights[x1][y1]<=mid){
                    q.push({x1,y1});
                    vis[x1][y1]=1;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        int lo=0,hi=1e7,mid,ans=1e7;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(check(heights,mid)){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return max(ans,heights[0][0]);
    }
};