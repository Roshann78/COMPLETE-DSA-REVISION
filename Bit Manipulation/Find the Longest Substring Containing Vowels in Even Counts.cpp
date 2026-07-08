class Solution {
public:
    int help(char c){
        if(c=='a'){
            return 0;
        }
        if(c=='e'){
            return 1;
        }
        if(c=='i'){
            return 2;
        }
        if(c=='o'){
            return 3;
        }
        if(c=='u'){
            return 4;
        }
        return -1;
    }
    int findTheLongestSubstring(string s) {
        
        int n=s.size();
        map<int,int>m;

        int ans=0;
        int mask=0;
        m[mask]=-1;
        for(int i=0;i<n;i++){
            int x=help(s[i]);
            if(x!=-1){
                mask=mask^(1LL<<x);
            }
            if(m.find(mask)!=m.end()){
                ans=max(ans,i-m[mask]);
                continue;
            }
            m[mask]=i;
        }
        return ans;
    }
};