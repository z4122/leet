class Solution {
public:
    
    
    int recur(int i,int j,vector<vector<int>>& grid)
    {
        int sum = 0;
        int h = grid.size();
        int w = grid[0].size();
        
        if(grid[i][j]==1){
            grid[i][j]=-1;
            sum++;
        }
        
        if(i-1>=0&&grid[i-1][j]==1) sum+=recur(i-1,j,grid);
        if((i+1<=h-1)&&grid[i+1][j]==1) sum+=recur(i+1,j,grid);
        if(j-1>=0&&grid[i][j-1]==1) sum+=recur(i,j-1,grid);
        if((j+1<=w-1)&&grid[i][j+1]==1) sum+=recur(i,j+1,grid);
        
        return sum;
        
    }
    
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;
        
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    ret = max(ret,recur(i,j,grid));
                    
                }
            }
        }
        return ret;
    }
};