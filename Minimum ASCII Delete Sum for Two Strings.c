class Solution {
public:   
    int minimumDeleteSum(string s1, string s2) {
	vector<vector<int>> c;
	c.resize(s1.size() + 1);
	for (int i = 0; i <= s1.size(); i++)
		c[i].resize(s2.size() + 1);
	int sum = 0;
	for (int i = 1; i <= s1.length(); i++)
		for (int j = 1; j <= s2.size(); j++)
		{
			if (s1.at(i - 1) == s2.at(j - 1))
				c[i][j] = c[i - 1][j - 1] + (int)s1.at(i - 1);
			else
				c[i][j] = max(c[i - 1][j], c[i][j - 1]);
		}

	for (int i = 0; i<s1.length(); i++)
		sum += (int)s1.at(i);
	for (int i = 0; i<s2.length(); i++)
		sum += (int)s2.at(i);
	return sum - 2 * c[s1.length()][s2.length()];

}
};

//动态规划中的最长公共子序列的变种，只是把统计个数的+1改成了+ASCII值