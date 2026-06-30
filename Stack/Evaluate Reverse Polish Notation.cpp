class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        
        stack<int>st;

        for(auto i:tokens){

            if(i=="*") {
                int x1=st.top();
                st.pop();
                int x2=st.top();
                st.pop();
                st.push(x1*x2);
                continue;
            }
            if( i=="-"){
                int x1=st.top();
                st.pop();
                int x2=st.top();
                st.pop();
                st.push(x2-x1);
                continue;
            }
            if(i=="+"){
                int x1=st.top();
                st.pop();
                int x2=st.top();
                st.pop();
                st.push(x1+x2);
                continue;
            }
            if(i=="/"){
                int x1=st.top();
                st.pop();
                int x2=st.top();
                st.pop();
                st.push(x2/x1);
                continue;
            }
            int x=stoi(i);
            st.push(x);
        }
        return st.top();
    }
};