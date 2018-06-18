class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> index;
        int max_val = 0;
        int output[2] = {0};
        if(nums.empty())
            return 0;
        if(nums.size()==1)
            return nums[0];
        for(auto val:nums)
        {
            index[val] +=val;
            max_val = max(val,max_val);
        }
        vector<int> earn(max_val+1,0);
        
        auto iter = index.begin();
        earn[iter->first] = iter->second;
        iter++;
        earn[iter->first] = iter->second;
        
        for(int i = 2;i<earn.size();i++)
        {
            earn[i] = max(earn[i-1],earn[i-2]+index[i]);
                        
        }
        return earn[max_val];
    }
};