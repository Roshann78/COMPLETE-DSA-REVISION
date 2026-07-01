class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();

        sort(intervals.begin(),intervals.end());

        vector<vector<int>>ans;

        int x=intervals[0][0];
        int y=intervals[0][1];

        for(int i=1;i<n;i++){
            if(intervals[i][0]<=y){
                y=max(y,intervals[i][1]);
                continue;
            }
            ans.push_back({x,y});
            x=intervals[i][0];
            y=intervals[i][1];
        }
        ans.push_back({x,y});

        return ans;
    }
};