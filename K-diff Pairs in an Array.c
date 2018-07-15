//超时的算法
class Solution {
public:
int findPairs(vector<int>& nums, int k) {
	map<int, int>temp;
	int output = 0;
	for (int i = 0; i<nums.size(); i++)
		temp[nums[i]]++;
	

	for (auto itera = temp.begin();itera!=temp.end();itera++)
		for (auto iterb = itera;iterb!=temp.end();iterb++)
		{
			if (iterb->first - itera->first == k)
			{
				output++;
				break;
			}
		}

	if (k == 0)
	{
		output = 0;
		for (auto iter = temp.begin(); iter != temp.end(); iter++)
		{
			if (iter->second > 1)
				output++;
		}
	}
	return output;
}
};

//次优解
class Solution {
public:
int findPairs(vector<int>& nums, int k) {
	map<int, int>temp;
	int output = 0;
    int temp_j = 0;
	for (int i = 0; i<nums.size(); i++)
		temp[nums[i]]++;
	vector<int> vtemp(temp.size());
    
	for (auto itera = temp.begin(); itera != temp.end(); itera++)
	{
	    vtemp[output] = itera->first;
        output++;
    }
    
    output = 0;
    
    for(int i = 0;i<vtemp.size();i++)
    {
        for(int j = temp_j;j<vtemp.size();j++)
        {
            if (vtemp[j]- vtemp[i] == k)
			{
				output++;
				temp_j = j+1;
				break;
			}
        }
    }
			
	if (k == 0)
	{
		output = 0;
		for (auto iter = temp.begin(); iter != temp.end(); iter++)
		{
			if (iter->second > 1)
				output++;
		}
	}
    
    if(k<0)
        return 0;
	return output;
}

};


//最后的循环用不到两层，一层就可以，直接找相应的数存不存在。