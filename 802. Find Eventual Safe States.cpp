802. Find Eventual Safe States

这个题注意，形参如果带&速度更快，不用拷贝

   vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        vector<int> visited(graph.size(), 0);
        for(int i = 0; i < graph.size(); i++){
            if(dfs(graph, visited, i)) res.push_back(i);
        }
        return res;
    }
	
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int i){
        if(visited[i]) return visited[i] == 1;
        visited[i] = -1;
        for(int j = 0; j < graph[i].size(); j++){
            if(!dfs(graph, visited, graph[i][j])) return false;
        }
        visited[i] = 1;
        return true;
    }
	
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ret;
        vector<int> dp(graph.size(),0);
        
        for(int i = 0;i<graph.size();i++)
        {
            if(Dfs(i,graph,dp)) ret.push_back(i);
        }
        return ret;
    }
       
    bool Dfs(int i,vector<vector<int>>& graph,vector<int>& dp)
    {
        if(dp[i])
            return dp[i]==1;
        dp[i] = -1;
        for(int j = 0;j<graph[i].size();j++)
        {
            if(Dfs(graph[i][j],graph,dp)==false){
                return false;   
            }
        }
        dp[i] = 1;
        return true;
    }