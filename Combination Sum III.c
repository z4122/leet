class Solution {
public:
    
    void help(int index,int k,int n,vector<int> temp,vector<vector<int>>&output)
    {
        if(temp.size()==k&&n == 0)
        {
            output.push_back(temp);
            return;
        }
        
        for(int i = index+1;i<10;i++)
        {
            temp.push_back(i);
            if((n-i)>=0)
                help(i,k,n-i,temp,output);
            temp.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> output;
        vector<int>temp;
        
        help(0,k,n,temp,output);
        
        return output;
    }
};