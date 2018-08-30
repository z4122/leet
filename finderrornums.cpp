class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> output;

        for(int val:nums)
        {
            nums[abs(val)-1]*=-1;
        }
        for(int i = 0;i<nums.size();++i)
        {
            if(nums[i]>0)
               output.push_back(i+1); 
        }
        for(int val:nums)
        {
            if(abs(val)==output[0])
                return output;
        }
        
        swap(output[0],output[1]);
        return output;
    }
};