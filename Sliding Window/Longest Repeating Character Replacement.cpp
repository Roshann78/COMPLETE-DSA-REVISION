class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();

        int ans=0,l=0,mx=0;
        map<char,int>m;

        for(int i=0;i<n;i++){
            m[s[i]]++;
            mx=max(mx,m[s[i]]);
            while(i-l+1-mx>k){
                m[s[l]]--;
                l++;
                int c=0;
                for(auto j:m){
                    c=max(c,j.second);
                }
                mx=c;
            }
            ans=max(ans,i-l+1);
        }
        return ans;
    }
};