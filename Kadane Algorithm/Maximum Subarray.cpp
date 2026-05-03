class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int ps=0;
        for(auto i:nums){
            ps+=i;
            ans=max(ans,ps);
            if(ps<=0){
                ps=0;
            }
        }
        return ans;
    }
};