class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size();
        int n=mat[0].size();
        if( m*n != r*c) return mat;
        vector<vector<int>>result(r,vector<int>(c));
        for(int i=0;i<m*n;i++){
            int oldrow=i/n;
            int oldcol=i%n;
            int newrow=i/c;
            int newcol=i%c;
            result[newrow][newcol]=mat[oldrow][oldcol];
        }
        return result;
    }
};