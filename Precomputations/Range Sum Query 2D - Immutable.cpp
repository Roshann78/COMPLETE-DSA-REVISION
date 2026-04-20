class NumMatrix {
public:
    vector<vector<int>>mat;
    vector<vector<int>>ps;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        mat.resize(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[i][j]=matrix[i][j];
            }
        }
        ps=mat;
        for(int i=0;i<n;i++)ps[i][0]=matrix[i][0];
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                ps[i][j]=ps[i][j-1]+matrix[i][j];
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                ps[j][i]+=ps[j-1][i];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        ans=ps[row2][col2];
        if(row1!=0 && col1!=0)
        {
            ans-=ps[row1-1][col2];
            ans-=ps[row2][col1-1];
            ans+=ps[row1-1][col1-1];
        }
        else if(col1!=0)
        {
            ans-=ps[row2][col1-1];
        }
        else if(row1!=0)
        {
            ans-=ps[row1-1][col2];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */