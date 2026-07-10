class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int n=nums.size();
        int p=1,ans=0,l=0;

        for(int i=0;i<n;i++){
            p*=nums[i];
            while(l<=i && p>=k){
                p/=nums[l];
                l++;
            }
            if(i>=l){
                ans+=i-l+1;
            }
        }
        return ans;
    }
};