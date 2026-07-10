class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>m;
        int p=-1;

        int n=s.size();
        int ans=0;

        for(int i=0;i<n;i++){
            if(m.find(s[i])!=m.end()){
                p=max(p,m[s[i]]);
            }
            ans=max(ans,i-p);
            m[s[i]]=i;
        }
        return ans;
    }
};