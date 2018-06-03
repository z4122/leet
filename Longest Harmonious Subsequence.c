
int findLHS(vector<int>& nums)
{
	int length = nums.size();
	int temp = 0, index = 0;
	int plus = 0, minus = 0, equal = 0;
	vector<int> temp_p, temp_m;
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length; j++)
		{
			if (nums[i] == nums[j])
				equal++;
			if (nums[i] == nums[j] - 1)
				minus++;
			if (nums[i] == nums[j] + 1)
				plus++;
		}
		if (plus == 0 && minus == 0)
		{
			equal = 0;
			continue;
		}
		if (plus + equal > temp)
		{
			temp = plus + equal;

		}
		if (minus + equal > temp)
		{
			temp = minus + equal;
		}
		equal = 0;
		plus = 0;
		minus = 0;
	}



	return temp;
}



    int findLHS(vector<int>& nums) 
 {
    sort(nums.begin(),nums.end());
    int equal = 0,plus = 0,minus = 0,temp = 0;
    for(int i = 0;i<nums.size();i++)
    {
        for(int j = i+1;j<nums.size();j++)
        {
            if(nums[i] == nums[j])
                equal++;
            if(nums[i] == nums[j]-1)
                plus++;
            if(nums[i]<nums[j]-1)   
                break;    
        }
        if(plus==0)
        {
            equal = 0;
            continue;
        }
        if (plus + equal +1> temp)
		{
			temp = plus + equal+1;

		}
		if (minus + equal +1> temp)
		{
			temp = minus + equal+1;
		}
		equal = 0;
		plus = 0;
		minus = 0;
        while(nums[i] == nums[i+1])
            i++;
    }
	return temp; 
 }