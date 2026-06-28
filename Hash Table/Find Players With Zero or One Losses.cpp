class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int,int>m1,m2;

        for(auto i:matches){
            m1[i[0]]++;
            m2[i[1]]++;
        }

        vector<vector<int>>ans(2);

        for(auto [x,y] :m1){
            if(m2.find(x)==m2.end()){
                ans[0].push_back(x);
            }
        }

        for(auto [x,y]:m2){
            if(y==1){
                ans[1].push_back(x);
            }
        }

        return ans;
    }
};