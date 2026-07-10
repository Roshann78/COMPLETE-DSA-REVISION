class Solution {
public:
    int appendCharacters(string s, string t) {
        int l=0;
        int n1=s.size(),n2=t.size();

        for(int i=0;i<n1;i++){
            if(s[i]==t[l]){
                l++;
            }
            if(l==n2){
                break;
            }
        }
        return n2-l;
    }
};