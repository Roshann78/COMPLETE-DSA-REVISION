class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx=0;
        for(auto i:nums){
            mx|=i;
        }

        int n=nums.size();
        int ans=0;
        for(int i=1;i<(1LL<<n);i++){
            int cor=0;
            for(int j=0;j<32;j++){
                if(((1LL<<j)&i)!=0){
                    cor|=nums[j];
                }
            }
            ans+=(cor==mx);
        }

        return ans;
    }
};