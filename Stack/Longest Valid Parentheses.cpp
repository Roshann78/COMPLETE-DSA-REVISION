class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int n=s.size();
        int ans=0;
        st.push(-1);

        for(int i=0;i<n;i++){

            if(s[i]=='('){
                st.push(i);
            }else{
                if(!st.empty()){
                    st.pop();
                }
                if(st.empty()){
                    st.push(i);
                }else{
                    ans=max(ans,i-st.top());
                }
            }
            
        }
        return ans;
    }
};




//another solution totally unique

class Solution {
public:
    int help(char c){
        if(c=='('){
            return 1;
        }
        return -1;
    }
    int longestValidParentheses(string s) {
        int n=s.size();
        map<int,int>m;
        int ans=0,c=0;
        m[0]=-1;
        for(int i=0;i<n;i++){
            c+=help(s[i]);
            if(c<0){
                m.clear();
                m[0]=i;
                c=0;
                continue;
            }
            if (s[i] == ')') {
                m.erase(c + 1); 
            }
            if(m.find(c)!=m.end()){
                ans=max(ans,i-m[c]);
                continue;
            }
            m[c]=i;
        }
        return ans;
    }
};