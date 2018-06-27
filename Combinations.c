class Solution {
public:
    void help(int index,int n,int k,vector<int>temp,vector<vector<int>>& output)
    {
        if(temp.size()==k)
        {
            output.push_back(temp);
            return;
        }
            if(index==n&&temp.size()<k)
            return;   
        for(int i = index+1;i<=n;i++)
        {
            temp.push_back(i);
            help(i,n,k,temp,output);
            temp.pop_back();
        }
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> output;
        vector<int> temp;
        
        help(0,n,k,temp,output);
        return output;
    }
};