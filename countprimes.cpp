class Solution {
public:
    int countPrimes(int n) {
	vector<int> index = { 2,3,5 };

    if(n==5||n==4)
        return 2;
    if(n==3)
        return 1;
    if(n<=2)
        return 0;
        
	for (int i = 6; i<n; i++)
	{
		for (auto val : index)
		{
			if (i%val == 0)
				break;
			else if (val == index.back())
			{
				index.push_back(i);
			}
		}
	}
	return index.size();
}
};

class Solution {
public:
    int countPrimes(int n) {
    if(n==0)
        return 0;
    int num[n] = {0};
    for(int i = 2;i<n;i++)
    {
        if(num[i]==0)
        {
            int j = 2;
            while(j*i<n){
                num[i*j] = 1;
                j++;
            }
        }
    }
    int j = 0;
    for(int i = 2;i<n;i++)
    {
        if(num[i]==0)
            j++;
    }
    return j;
    }
};