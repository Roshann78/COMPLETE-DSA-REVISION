class Solution {
public:
    bool check(vector<int>&derived,int x,int y){
        int n=derived.size();
        for(int i=1;i<n;i++){
            y=y^derived[i];
        }
        return y==x;

    }
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        
        if(n==1){
            return derived[0]==0;
        }

        if(derived[0]==1){
            return check(derived,0,1) || check(derived,1,0);
        }else{
            return check(derived,0,0) || check(derived,1,1);
        }

        return true;
    }
};