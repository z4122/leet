547. Friend Circles


class Solution {
public:
    
    void Dfs(vector<vector<int>>& M,int i)
    {
        for(int j = 0;j<M[0].size();j++)
        {
            if(M[i][j]==1){
                M[i][j]=-1;
                Dfs(M,j);        
            }
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        if(M.size()==0)
            return 0;
        
        int ret = 0;
        
        for(int i = 0;i<M.size();i++)
            for(int j = 0;j<M[0].size();j++)
            {
                if(M[i][j]==1){
                    ret++;
                    Dfs(M,i);   
                }
            }
        
        return ret;
    }
};