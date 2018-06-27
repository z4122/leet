    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> temp(nums.size()+1,0);
        vector<int> output;
        for(int i = 0;i<nums.size();i++)
        {
            if(++temp[nums[i]]==2)
                output.push_back(nums[i]);
        }
        return output;
    }