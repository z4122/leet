class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int slow = 1,fast = 1;
        int last = nums[0];
        int flag = 0;
        for(;fast<nums.size();fast++)
        {
            if(nums[fast] == last)
            {
                if(flag==0){
                    nums[slow++] = nums[fast];
                    flag++;
                }
                else{
                    continue;
                }
            }
            else{
                last = nums[fast];
                nums[slow] = last;
                slow++;
                flag = 0;
            }
        }
        return slow;
    }
};