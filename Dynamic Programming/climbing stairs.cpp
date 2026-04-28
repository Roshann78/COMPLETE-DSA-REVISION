class Solution {
public:
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        int ans=2;
        int x=1,y=2;
        for(int i=3;i<=n;i++){
            ans=x+y;
            x=y;
            y=ans;
        }
        return ans;
    }
};