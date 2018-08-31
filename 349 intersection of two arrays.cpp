class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> output;
        unordered_map<int,bool> num1;
        for(auto val:nums1)
            num1[val]++;
        for(auto val:nums2){
            if(num1[val]){
                output.push_back(val);
                num1[val]-=1;
            }
                
        }
        return output;
    }
};