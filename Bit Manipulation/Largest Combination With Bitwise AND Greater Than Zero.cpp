class Solution {
public:
    int largestCombination(vector<int>& nums) {
        int ans=0;

        for(int i=0;i<32;i++){
            int c=0;
            for(auto j:nums){
                if(((1LL<<i)&j)!=0){
                    c++;
                }
            }
            ans=max(ans,c);
        }
        return ans;
    }
};