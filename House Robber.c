class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> temp = nums;
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return nums[0]>nums[1]?nums[0]:nums[1];
        temp[0] = nums[0];
        temp[1] = nums[1];
        temp[2] = temp[0]+nums[2];
        for(int i = 3;i<nums.size();i++)
        {
            temp[i] = max(temp[i - 3], temp[i - 2])+nums[i];
        }
        if(temp[nums.size()-1]>temp[nums.size()-2])
        {
            return temp[nums.size()-1];
        }
        else
            return temp[nums.size()-2];
    }
};