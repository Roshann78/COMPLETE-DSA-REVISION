class Solution {
public:
    int count(int n){
        int ans=0;
        for(int i=0;i<32;i++){
            if(((1LL<<i)&n)!=0){
                ans++;
            }
        }
        return ans;
    }
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();

        vector<int>v=nums;
        sort(v.begin(),v.end());

        for(int i=0;i<n;i++){
            int r=upper_bound(v.begin(),v.end(),nums[i])-v.begin()-1;
            int c=count(nums[i]);
            for(int j=i;j<=r;j++){
                if(count(nums[i])!=count(nums[j])){
                    return false;
                }
                int x=upper_bound(v.begin(),v.end(),nums[j])-v.begin()-1;
                r=max(r,x);
            }
            i=r;
        }


        return true;

    }
};