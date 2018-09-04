class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int output = 0;
        sort(nums.begin(),nums.end());
        for(auto val:nums)
            output = output + abs(val-nums[nums.size()/2]);
        return output;
    }
};