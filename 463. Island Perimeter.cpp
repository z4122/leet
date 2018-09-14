class Solution {
public:
    
     void recur(int i,int j,vector<vector<int>>& grid,int& ret)
    {
        int h = grid.size();
        int w = grid[0].size();
        
        if(grid[i][j]==1){
            grid[i][j]=-1;
            
            if(i-1<0||grid[i-1][j]==0) ret++;
            if((i+1>h-1)||grid[i+1][j]==0) ret++;
            if(j-1<0||grid[i][j-1]==0) ret++;
            if((j+1>w-1)||grid[i][j+1]==0) ret++;
        }
        
        if(i-1>=0&&grid[i-1][j]==1) recur(i-1,j,grid,ret);
        if((i+1<=h-1)&&grid[i+1][j]==1) recur(i+1,j,grid,ret);
        if(j-1>=0&&grid[i][j-1]==1) recur(i,j-1,grid,ret);
        if((j+1<=w-1)&&grid[i][j+1]==1) recur(i,j+1,grid,ret);
        

        
    }
    
    

    
    int islandPerimeter(vector<vector<int>>& grid) {
        int ret = 0;
        
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    recur(i,j,grid,ret);
                    
                }
            }
        }
        
        return ret;
    
    }
};