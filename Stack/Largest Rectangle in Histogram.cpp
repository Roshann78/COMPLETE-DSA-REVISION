class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int>ps(n),ns(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ps[i]=st.top();
            }else{
                ps[i]=-1;
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ns[i]=st.top();
            }else{
                ns[i]=-1;
            }
            st.push(i);
        }

        int ans=0;

        for(int i=0;i<n;i++){
            if(ns[i]!=-1 && ps[i]!=-1){
                ans=max(ans,heights[i]*(ns[i]-ps[i]-1));
                continue;
            }
            if(ns[i]==-1){
                ans=max(ans,heights[i]*(n-ps[i]-1));
                continue;
            }
            if(ps[i]==-1){
                ans=max(ans,heights[i]*ns[i]);
                continue;
            }
            ans=max(ans,heights[i]*n);
        }
        return ans;

    }
};