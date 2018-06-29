class Solution {
public:
    
    void help(int index,int target,vector<int>candidates,vector<int>&temp,vector<vector<int>>&output)
    {
        
        if(target==0)
            output.push_back(temp);
        else if(target<0)
            return;
        
        for(int i = index;i<candidates.size();i++)
        {
            temp.push_back(candidates[i]);
            help(i+1,target-candidates[i],candidates,temp,output);
            temp.pop_back();
        }
    }
    
    
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> output;
        vector<int> temp;
        
        help(0,target,candidates,temp,output);
        
        sort(output.begin(),output.end());
        output.erase(unique(output.begin(),output.end()),output.end());
        
        return output;
    }
};