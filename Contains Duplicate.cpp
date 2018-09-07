class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> temp;
        if(nums.size()==0)
            return false;
        for(auto val:nums)
        {
            temp[val]++;
            if(temp[val]>1)
                return true;
        }
        return false;
    }
};