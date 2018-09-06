美团动态规划题目 输入N个为0或1的数，最多把m个0改为1，请问最多能有几个连续的1
用动态规划的思路实现。


int test(int len, int cnt,vector<int> input)
{
	vector<vector<int>>dp(input.size(),vector<int>(2,0));
	int  temp= 0;
	int  output = 0;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == 0) temp++;
		if (temp == cnt) {
			temp = i;
			break;
		}
	}

	dp[temp][0] = temp+1;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == 0)
		{
			dp[temp][1] = i;
			break;
		}
	}

	for (int i = temp+1; i < input.size(); i++)
	{

		if (input[i] == 1) {
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = dp[i - 1][1];
		}
		else
		{
			dp[i][1] = dp[i - 1][1]+1;
			dp[i][0] = i - dp[i][1] + 1;
			while (input[dp[i][1]] == 1)
			{
				dp[i][1]++;
			}
		}
		output = std::max(output, dp[i][0]);
	}

	return output;
}