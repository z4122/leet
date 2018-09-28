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


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), res = n;
        vector<int> root(n);
        for (int i = 0; i < n; ++i) root[i] = i;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (M[i][j] == 1) {
                    int p1 = getRoot(root, i);
                    int p2 = getRoot(root, j);
                    if (p1 != p2) {
                        --res;
                        root[p2] = p1;
                    }
                }
            }   
        }
        return res;
    }
    int getRoot(vector<int>& root, int i) {
        while (i != root[i]) {
            root[i] = root[root[i]];
            i = root[i];
        }
        return i;
    }
};