698. 划分为k个相等的子集

给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。

示例 1：

输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
输出： True
说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。


class Solution {
public:
    bool Dfs(vector<int> &isused, vector<int>& nums,int start, int setnum, int k, int subsum, int targetsum) {
	if (setnum == k)
		return true;
	if (subsum == targetsum) {
		return Dfs(isused, nums, 0,setnum + 1, k, 0, targetsum);		
	}
	else if (subsum > targetsum) {
		return false;
	}
		

	for (int i = start; i<isused.size(); i++) {
		if (isused[i] == 0) {
			isused[i] = 1;
			if (Dfs(isused, nums, i+1,setnum, k, subsum + nums[i], targetsum))
				return true;
			isused[i] = 0;
		}
	}
	return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
	int sum = 0;
	for (auto val : nums)
		sum += val;
	int subsum = sum / k;

	if (sum%k != 0)
		return false;

	vector<int> isused(nums.size(), 0);

	return Dfs(isused, nums,0, 0, k, 0, subsum);
}
};