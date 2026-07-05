class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        map<int,vector<int>>m;
        int s=arr[0];
        m[0].push_back(-1);
        m[s].push_back(0);
        for(int i=1;i<n;i++){
            s^=arr[i];
            for(auto j:m[s]){
                ans+=i-j-1;
            }
            m[s].push_back(i);
        }
        return ans;
    }
};