class Solution {
public:
    int findComplement(int num) {
        int ans=0;

        for(int i=32;i>=0;i--){
            if(((1LL<<i)&num)!=0){
                // cout<<i<<endl;
                return num^((1LL<<(i+1))-1);
            }
        }
        return 0;
    }
};