class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> dp(nums.size(),1),cn(nums.size(),1);      
        int dp_max = 1;
        int output = 0;
        for(int i = 0;i<nums.size();i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[j]<nums[i]&&dp[j]+1>dp[i])
                {                    
                    dp[i] = dp[j]+1;
                    cn[i] = cn[j];
                }
                else if(nums[j]<nums[i]&&dp[j]+1==dp[i])
                {
                    dp[i] = dp[j]+1;
                    cn[i] += cn[j];                    
                }

            }
            dp_max = max(dp_max,dp[i]);
        }
        
        for(int i = 0;i<nums.size();i++)
        {
            if(dp[i]==dp_max)
                output += cn[i];
        }
        return output;
    }
};