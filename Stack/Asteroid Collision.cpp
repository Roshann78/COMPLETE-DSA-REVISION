class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;

        for(auto i:asteroids){
            if(i>0){
                st.push(i);
                continue;
            }
            if(st.empty() || st.top()<0){
                st.push(i);
                continue;
            }
            while(!st.empty() && st.top()<abs(i) && st.top()>0){
                st.pop();
            }
            if(!st.empty() && st.top()==abs(i) ){
                st.pop();
                continue;
            }
            if(st.empty() || st.top()<0){
                st.push(i);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};