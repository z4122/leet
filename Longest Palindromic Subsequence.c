class Solution {
public: 
   int compute(string s, int index)
{
	int len = s.size();
	int first_condition = 0, second_condition = 0;
	vector<vector<int>> temp(index+1);
	temp[0].resize(len - index+1, 0);

	//从中间的空隙开始分
	for (int i = 1; i<=index; i++)
	{
		temp[i].resize(len - index+1, 0);
		for (int j = 1; j<=len - index; j++)
		{
			if (s.at(index - i) == s.at(index + j - 1))
				temp[i][j] = temp[i - 1][j - 1] + 1;
			else
				temp[i][j] = max(temp[i - 1][j], temp[i][j - 1]);

		}
	}
	first_condition = temp[index][len - index]*2;

	

	//从中间的值开始分
	for (int i = 1; i<=index; i++)
	{
		
		for (int j = 1; j<len - index; j++)
		{
			if (s.at(index - i) == s.at(index + j))
				temp[i][j] = temp[i - 1][j - 1] + 1;
			else
				temp[i][j] = max(temp[i - 1][j], temp[i][j - 1]);

		}
	}
	second_condition = temp[index][len - index - 1]*2+1;

	return max(first_condition, second_condition);
}


int longestPalindromeSubseq(string s) {
	int output = 1;
    if(s.size()==0)
        return 0;
	for (int i = 1; i<s.size(); i++)
		output = max(compute(s, i), output);
	return output;

}
};




class Solution {
public: 
    int longestPalindromeSubseq(string s) {
	    int len = s.size();
        int output = 0;
        if(len==1)
            return 1;
        vector<vector<int>> dp(len,vector<int>(len));
        for(int i = len-1;i>=0;i--)
        {
            dp[i][i] = 1;
            for(int j = i+1;j<len;j++)
            {
                if(s.at(i)==s.at(j))
                    dp[i][j] = dp[i+1][j-1]+2;
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                output = max(output,dp[i][j]);
            }
        }
        return output;
       

}
};