class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>> temp;
        int min_value = INT_MAX;
        for(int i = 0;i<nums.size();i++)
        {
            temp[nums[i]].push_back(i);
        }
        for(auto iter = temp.begin();iter!=temp.end();iter++)
        {
            for(int i = 1;i<iter->second.size();i++)
                min_value = min(min_value,iter->second[i]-iter->second[i-1]);
            if(min_value<=k)
                return true;
        }       
        return false;
    }
};