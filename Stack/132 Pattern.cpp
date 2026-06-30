class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector<int>pmn(n,-2e9);
        pmn[0]=0;
        for(int i=1;i<n;i++){
            if(nums[pmn[i-1]]<=nums[i]){
                pmn[i]=pmn[i-1];
                continue;
            }
            pmn[i]=i;
        }
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(!st.empty()){
                int x=st.top();
                if(pmn[x]!=x && nums[pmn[x]]<nums[i]){
                    return true;
                }
            }
            st.push(i);
        }
        return false;
    }
};