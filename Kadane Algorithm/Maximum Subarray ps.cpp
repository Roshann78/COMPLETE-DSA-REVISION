class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int s=0,ps=0;
        for(auto i:nums){
            ps+=i;
            ans=max(ans,ps-s);
            s=min(s,ps);
        }
        return ans;
    }
};