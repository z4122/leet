bool compare(vector<int>a, vector<int>b)
{
	
		return a[1]>b[1];
}

vector<int> topKFrequent(vector<int>& nums, int k) 
{
	map<int, int> index;
	multimap<int, int> sort_index;
	vector<int>output;
	int i = 0;
	for (auto val : nums)
		index[val]++;

	vector<vector<int>> temp(nums.size(), vector<int>(2, 0));

	for (auto iter = index.begin(); iter != index.end(); iter++, i++)
	{
		temp[i][0] = iter->first;
		temp[i][1] = iter->second;
	}

	sort(temp.begin(), temp.end(), compare);

	for (int i = 0; i < k; i++)
		output.push_back(temp[i][0]);
	return output;
}