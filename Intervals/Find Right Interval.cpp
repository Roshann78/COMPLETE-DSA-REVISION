class Solution {
public:
    int help(vector<pair<int,int>>&v,int c){
        int l=0,r=v.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(v[mid].first>=c){
                ans=v[mid].second;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int>ans(n);
        vector<pair<int,int>>v;

        for(int i=0;i<n;i++){
            v.push_back({intervals[i][0],i});
        }

        sort(v.begin(),v.end());

        for(int i=0;i<n;i++){
            int x=help(v,intervals[i][1]);

            ans[i]=x;
        }
        return ans;
    }
};