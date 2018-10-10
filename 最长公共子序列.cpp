最长公共子序列

int findLength(vector<int>& A, vector<int>& B) {
	int row = A.size();
	int colum = B.size();
	int output = 0;
	vector<vector<int>> dp(row, vector<int>(colum, 0));

	for (int i = 0; i < row; i++) {
		if (A[i] == B[0])
			dp[i][0]++;
	}

	for (int i = 1; i<colum; i++) {
		if (A[0] == B[i])
			dp[0][i]++;
	}

	for (int i = 1; i<row; i++)
		for (int j = 1; j<colum; j++)
		{
			if (A[i] == B[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				output = max(output, dp[i][j]);
			}
		}
	return output;
}