//304. Range Sum Query 2D - Immutable
class NumMatrix {
public:
    int h = 0;
    int w = 0;
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        h = matrix.size();
        if(h > 0)  w = matrix[0].size();
        sum = vector<vector<int>>(h+1, vector<int>(w+1,0));
        for(int i =1; i<=h; i++)
        {
            for(int j=1; j<=w; j++)
            {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row1][col2+1] - sum[row2+1][col1] + sum[row1][col1];
    }
};
