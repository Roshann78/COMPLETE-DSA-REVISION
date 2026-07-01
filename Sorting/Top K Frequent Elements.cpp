class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;

        for(auto i:nums){
            m[i]++;
        }
        for(auto [x,y]:m){
            pq.push({y,x});
        }

        vector<int>ans;

        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};