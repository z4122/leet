class Solution {
public: 
    int minPathSum(vector<vector<int>>& grid) {
        int output = 0;
        vector<vector<int>> temp = grid;
        for(int i = 1;i<grid.size();i++)
            temp[i][0] += temp[i-1][0];
        for(int i = 1;i<grid[0].size();i++)
            temp[0][i] += temp[0][i-1];
        
        for(int i = 1;i<grid.size();i++)
            for(int j = 1;j<grid[0].size();j++)
            {
                temp[i][j] += min(temp[i-1][j],temp[i][j-1]);               
            }
        return temp[grid.size()-1][grid[0].size()-1];
    }
};