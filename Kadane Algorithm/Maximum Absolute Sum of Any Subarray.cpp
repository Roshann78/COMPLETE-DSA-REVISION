class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=abs(nums[0]);
        int s1=0,s2=0,ps=0;
        for(auto i:nums){
            ps+=i;
            ans=max(ans,ps-s1);
            ans=max(ans,abs(ps-s2));
            s1=min(s1,ps);
            s2=max(s2,ps);
        }
        return ans;
    }
};