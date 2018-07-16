class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>temp(nums);
        if(nums.size()==1)
            return;
        int i = 0,j = nums.size()-1;
        for(auto val:temp)
        {
            if(val==0)
            {
                nums[i] = 0;
                i++;
                continue;
            }
            if(val == 2)
            {
                nums[j] = 2;
                j--;
                continue;
            }
        }
        while(i<=j)
        {
            nums[i] = 1;
            i++;
        }
    }
};