class Solution {
public:
    void help(int index,int target,vector<int>&temp,vector<int>& candidates,vector<vector<int>>&output)
    {
        
        if(target==0)
            output.push_back(temp);
        else if(target<0)
            return;
        
        for(int i = index;i<candidates.size();i++)
        {
            temp.push_back(candidates[i]);
            help(i,target-candidates[i],temp,candidates,output);
            temp.pop_back();
        }
    }
    
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> temp;
        help(0,target,temp,candidates,output);
        return output;
    }
};