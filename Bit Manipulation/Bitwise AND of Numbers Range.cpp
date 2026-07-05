class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int f=0;
        int ans=0;
        for(int i=31;i>=0;i--){
            if(((1LL<<i)&right)!=0){
                if(!f){
                    if(((1LL<<i)&left)==0){
                        return 0;
                    }else{
                        f=1;
                        ans+=(1LL<<i);
                    }
                }else{
                    if(((1LL<<i)&left)!=0){
                        ans+=(1LL<<i);
                    }else{
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};

/*

    ONE MORE HIGLY NON-INTUTIVE SOLUTIONS IS

    while(right>left){
        right&=right-1;
    }

    return right;

*/