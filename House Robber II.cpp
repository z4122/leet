class Solution {
public:
    
    void rob1(vector<int>&nums,vector<vector<int>>&dp)
    {
        int len = nums.size();
        dp[0][1] = nums[0];
        dp[1][0] = nums[0];
        dp[2][1] = nums[0]+nums[2];
        dp[2][0] = nums[0];
        for(int i = 3;i<nums.size();i++)
        {
            dp[i][1] = max(dp[i-2][1],dp[i-3][1])+nums[i];
            dp[i][0] = max(dp[i - 1][1],dp[i-1][0]);
        }      
    }
    
    void rob2(vector<int>&nums,vector<vector<int>>&dp)
    {
        int len = nums.size();
        dp[1][1] = nums[1];
        dp[2][1] = nums[2];
        dp[2][0] = nums[1];
        for(int i = 3;i<nums.size();i++)
        {
            dp[i][1] = max(dp[i-2][1],dp[i-3][1])+nums[i];
            dp[i][0] = max(dp[i - 1][1],dp[i-1][0]);
        }      
    }
    
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(nums.size()==0)
            return 0;
        if(len==2)
            return max(nums[0],nums[1]);      
        if(len==1)
            return nums[0];
        if(len==3)
            return max(max(nums[0],nums[1]),nums[2]);
        
        vector<vector<int>> dp(len,vector<int>(len,0));
         vector<vector<int>> dp1(len,vector<int>(len,0));
        rob1(nums,dp);
        int ret1 = dp[nums.size()-1][0];
        
        
        rob2(nums,dp1);
        int ret2 = max(dp1[nums.size()-1][1],dp1[nums.size()-1][0]);
        
        return max(ret1,ret2);
    }
};