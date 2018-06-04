class Solution {
public:
   int rotatedDigits(int N) {
	vector<int> len;
	int temp = 0;
	int count = 0;

	for (int j = 1; j<N + 1; j++)
	{
		temp = j;
		while (temp)
		{
			len.push_back(temp % 10);
			temp = temp / 10;
		}
		int a = 0,b = 0;
		for (int i = 0; i<len.size(); i++)
		{
			if (len[i] == 3 || len[i] == 4 || len[i] == 7)
				break;
			if (len[i] == 0 || len[i] == 1 || len[i] == 8)
				a++;
			if (len[i] == 2 || len[i] == 5 || len[i] == 6 || len[i] == 9)
				b++;
			if (a + b == len.size()&&b!=0)
				count++;
		}
		
		len.clear();
	}
	return count;
}
};


//一个更简单的方法，可以把大的数拆成小的数进行判断，如15可以拆成1和5进行判断，115可以拆成1和15判断。