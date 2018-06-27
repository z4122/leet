class Solution {
public:
int findShortestSubArray(vector<int>& nums) {
	vector<int> temp = nums;
	vector<int> max_array_number;
	int last = 0, now = 0, count = 1, max_length = 0;
	int begin = 0, end = 0, min_length = 50001;
	sort(temp.begin(), temp.end());

	if (nums.size() == 0)
		return 0;
    
    if (nums.size() == 1)
		return 1;
	last = temp[0];
	for (int i = 1; i<nums.size(); i++)
	{
		now = temp[i];
		if (last == now)
		{
			count++;
		}
		else
		{
			count = 1;
			last = now;
		}
		max_length = max(max_length, count);
	}

	last = temp[0];
    count = 1;
	for (int i = 1; i<nums.size(); i++)
	{
		now = temp[i];
		if (last == now)
		{
			count++;

		}
		else
		{
			count = 1;
			last = now;
		}
		if (count == max_length)
			max_array_number.push_back(now);
	}

	count = 1;
	for (int i = 0; i<max_array_number.size(); i++)
	{
		for (int j = 0; j<nums.size(); j++)
		{
			if (nums[j] == max_array_number[i])
			{
				begin = j;
				break;
			}
		}
		for (int j = nums.size() - 1; j>=begin; j -- )
		{
			if (nums[j] == max_array_number[i])
			{
				end = j;
				break;
			}
		}
		min_length = min(min_length, end - begin + 1);
	}
	return min_length;
}
};