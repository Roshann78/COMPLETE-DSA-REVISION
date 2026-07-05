class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }

        for(int i=0;i<32;i++){
            if(m.find(1LL<<i)==m.end()){
                return (1LL<<i);
            }
        }

        return 0;
    }
};