class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);

        sort(intervals.begin(),intervals.end());

        vector<vector<int>>ans;

        int x=intervals[0][0],y=intervals[0][1];

        int n=intervals.size();

        for(int i=1;i<n;i++){
            if(intervals[i][0]>y){
                ans.push_back({x,y});
                x=intervals[i][0];
                y=intervals[i][1];
                continue;
            }
            y=max(y,intervals[i][1]);
        }
        ans.push_back({x,y});

        return ans;
    }
};