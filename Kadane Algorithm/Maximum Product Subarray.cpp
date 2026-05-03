class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0],p=1;
        for(auto i:nums){
            p*=i;
            ans=max(ans,p);
            if(p==0)p=1;
        }
        reverse(nums.begin(),nums.end());//faltu ka kiya hua kyuki for m auto use krne ka man tha
        p=1;
        for(auto i:nums){
            p*=i;
            ans=max(ans,p);
            if(p==0)p=1;
        }   
        return ans;
    }
};