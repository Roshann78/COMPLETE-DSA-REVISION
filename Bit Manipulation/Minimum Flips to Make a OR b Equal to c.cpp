class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;

        for(int i=0;i<32;i++){
            if(((1LL<<i)&c)==0){
                ans+=(((1LL<<i)&a)!=0)+(((1LL<<i)&b)!=0);
                continue;
            }
            ans+=((((1LL<<i)&a)==0)&&(((1LL<<i)&b)==0));
        }
        return ans;
    }
};