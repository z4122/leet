class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0;i+1<len;i++)
        {
            if(nums[i+1]>nums[i])
                continue;
            else
                return nums[i+1];
        }
        return nums[0];
    }
};