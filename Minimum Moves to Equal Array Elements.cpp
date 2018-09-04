class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_number = INT_MAX;
        int output = 0;
        for(auto val:nums) min_number = min(min_number,val);
        for(auto val:nums) output = output+ val-min_number;
        return output;
    }
    
};