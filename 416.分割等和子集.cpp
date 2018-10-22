416.分割等和子集
背包问题怎么给忘了？

给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意:

每个数组中的元素不会超过 100
数组的大小不会超过 200
示例 1:

输入: [1, 5, 11, 5]

输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].
 

示例 2:

输入: [1, 2, 3, 5]

输出: false

解释: 数组不能分割成两个元素和相等的子集.
 

class Solution {
public: 
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(auto val:nums){
        sum+=val;
    }
    
    
    if(sum%2!=0)
        return false;
    
    vector<int> dp(sum/2+1,0);
    dp[0] = true;
    
    
    for(int i = 0;i<nums.size();i++)
    {
        for(int j = sum/2;j>=nums[i];j--){
            dp[j] = dp[j]||dp[j-nums[i]];
        }
        if(dp[sum/2]==1)
            return true;
    }
    


        return false;
}
};

class Solution {
public: 
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(auto val:nums){
        sum+=val;
    }
    
    
    if(sum%2!=0)
        return false;
    
    vector<vector<int>> dp(nums.size(),vector<int>(sum/2+1,0));
    
    for(int i = nums[i];i<=sum/2;i++){
        dp[0][i] = nums[0];
    }
    
    for(int i = 1;i<nums.size();i++){
        for(int j = nums[i];j<=sum/2;j++){
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-nums[i]]+nums[i]);
        }
    }
    
    if(dp[nums.size()-1][sum/2]==sum/2)
        return true;
    else
        return false;
}
};