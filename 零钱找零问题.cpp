零钱找零问题

	vector<vector<int>> dp(couponTypes, vector<int>(maxDistance+1, 0));

	for (int i = 0; i < couponTypes; i++)
	{
		dp[i][0] = 1;
	}

	for (int i = 0; i < maxDistance+1; i++)
	{
		if (i%couponValues[0] == 0)
			dp[0][i] = 1;
	}

	for(int i = 1;i<couponTypes;i++)
		for(int j = 1;j<maxDistance+1;j++)
			for (int k = 0; k <= j / couponValues[i]; k++)
			{
				dp[i][j] += dp[i - 1][j - k * couponValues[i]];
			}