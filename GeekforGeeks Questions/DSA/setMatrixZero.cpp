class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> temp;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0)
                {
                    temp.push_back(make_pair(i,j));
                }
            }
        }
        for(int i=0; i<temp.size();i++){
            int row=temp[i].first;
            int col=temp[i].second;
            for(int j=0;j<matrix.size();j++){
                for(int k=0;k<matrix[j].size();k++){
                    if(j==row)
                    matrix[j][k]=0;
                    if(k==col)
                    matrix[j][k]=0;
                }
            }
        }
    }
};