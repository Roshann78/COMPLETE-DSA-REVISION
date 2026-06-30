class Solution {
public:
    string removeStars(string s) {
        stack<char>st;

        string ans="";
        for(auto i:s){
            if(i!='*'){
                st.push(i);
                continue;
            }
            if(!st.empty()){
                st.pop();
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};