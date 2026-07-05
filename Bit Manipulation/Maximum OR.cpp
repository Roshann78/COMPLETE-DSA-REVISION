class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        long long n=nums.size();
        vector<int>v1=nums,v2=nums;

        for(long long i=1;i<n;i++){
            v1[i]|=v1[i-1];
        }
        for(long long j=n-2;j>=0;j--){
            v2[j]|=v2[j+1];
        }

        if(n==1){
            return 1LL*nums[0]<<k;
        }
        long long ans=0;

        for(long long i=0;i<n;i++){
            if(!i){
                ans=max(ans,v2[i+1]|(1LL*nums[i]<<k));
                continue;
            }
            if(i==n-1){
                ans=max(ans,v1[i-1]|(1LL*nums[i]<<k));
                continue;
            }
            ans=max(ans,v1[i-1]|v2[i+1]|(1LL*nums[i]<<k));
        }
        return ans;
    }
};