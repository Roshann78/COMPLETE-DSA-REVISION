class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int i=0,j=0;

        int n=mat.size(),m=mat[0].size();
        int dir=1;

        while(1){
            
            ans.push_back(mat[i][j]);
            if(i==n-1 && j==m-1){
                break;
            }
            if(!dir){
                if(i==n-1){
                    j++;
                    dir^=1;
                }else if(j==0){
                    i++;
                    dir^=1;
                }
                else{
                    i++;
                    j--;
                }
            }else{
                if(j==m-1){
                    i++;
                    dir^=1;
                }else if(i==0){
                    j++;
                    dir^=1;
                }else{
                    i--;
                    j++;
                }
            }
        }
        return ans;
    }
};