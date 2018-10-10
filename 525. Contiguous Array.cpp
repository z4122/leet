525. Contiguous Array

技巧性很强的题，把0变为-1

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>index;
        
        for(int i = 0;i<nums.size();i++)
            if(nums[i]==0)
                nums[i] = -1;
        
        index[0] = -1;
        
        int sum = 0;
        int output = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(index.count(sum))
                output = max(output,i-index[sum]);
            else
                index[sum] = i;      
        }
        
        return output;
    }
};