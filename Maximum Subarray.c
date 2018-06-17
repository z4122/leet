class Solution {
public:
    int maxSubArray(vector<int>& nums) {    
        if(nums.size()==0)
            return 0;
        vector<int> temp(nums.size());  
        int output = nums[0];
        temp[0] = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            if(temp[i-1]>0)
                temp[i] = temp[i-1]+nums[i];
            else
                temp[i] = nums[i];
            output = max(output,temp[i]);
        }
        return output;
    }
};