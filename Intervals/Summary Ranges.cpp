class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n=nums.size();

        if(!n){
            return ans;
        }
        int x=0,y=0;

        for(int i=1;i<n;i++){
            if((1LL*nums[i]-nums[x])==i-x){
                y=i;
                continue;
            }
            if(x==y){
                ans.push_back(to_string(nums[x]));
            }else{
                ans.push_back(to_string(nums[x])+"->"+to_string(nums[y]));
            }
            x=i;
            y=i;
        }
        if(x==y){
            ans.push_back(to_string(nums[x]));
        }else{
            ans.push_back(to_string(nums[x])+"->"+to_string(nums[y]));
        }
        return ans;
    }
};