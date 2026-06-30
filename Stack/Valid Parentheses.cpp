class Solution {
public:
    bool isValid(string s) {
        int n=s.size();

        stack<char>st;

        for(auto i:s){

            if(i==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }else{
                    return false;
                }
                continue;
            }
            if(i=='}'){
                if(!st.empty() && st.top()=='{'){
                    st.pop();
                }else{
                    return false;
                }
                continue;
            }
            if(i==']'){
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }else{
                    return false;
                }
                continue;
            }
            st.push(i);
        }
        return st.size()==0;
    }
};