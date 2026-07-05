class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans=n*2;

        map<int,vector<int>>m;

        for(auto i:reservedSeats){
            int r=i[0],c=i[1];

            m[r].push_back(c);
        }

        //kya jrurat bitmasks ka just ek O(13) reduces to O(4)
        for(auto [x,y]:m){
            vector<int>ch{0,1,1,1,1,1,1,1,1,0};
            for(auto i:y){
                ch[i-1]=0;
            }
            for(int i=1;i<10;i++){
                ch[i]+=ch[i-1];
            }
            ans-=2;
            if(ch[4]-ch[0]==4){
                ans++;
            }else if(ch[6]-ch[2]==4){
                ans++;
                continue;
            }
            ans+=((ch[8]-ch[4])==4);
        }

        return ans;

    }
};