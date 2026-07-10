class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](vector<int>a,vector<int>b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];

        });

        int x=intervals[0][0],y=intervals[0][1];
        int ans=0;

        int n=intervals.size();

        for(int i=1;i<n;i++){
            if(intervals[i][1]<=y){
                continue;
            }
            ans++;
            x=intervals[i][0];
            y=intervals[i][1];
        }
        ans++;

        return ans;
    }
};