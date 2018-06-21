class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int a = matrix.size(),b = matrix[0].size();
        if(a==1&&b==1)
            return 1;
        for(int i = 1;i<a;i++)
        {
            for(int j = 1;j<b;j++)
            {
                if(matrix[i][j] != matrix[i-1][j-1])
                    return 0;
            }
        }
        return 1;
    }
};