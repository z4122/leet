18. 4Sum
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> output;
        
        if(nums.size()<=3)
            return output;
        
        for(int i = 0;i<nums.size()-3;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                continue;

            for(int j = i+1;j<nums.size()-2;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1])
                    continue;
                int m = j+1;
                int n = nums.size()-1;
                while(m<n){
                    int mm = nums[m];
                    int nn = nums[n];
                    int result = nums[i]+nums[j]+nums[m]+nums[n];
                    if(result==target){
                        output.push_back(vector<int>({nums[i],nums[j],nums[m],nums[n]}));
                        while(m<n&&nums[m]==mm) m++;
                        while(m<n&&nums[n]==nn) n--;
                    }
                    else if(result<target)
                        m++;
                    else if(result>target)
                        n--;
                }
            }
        }
        return output;
    }
};