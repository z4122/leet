最长公共子序列的变种题，还不熟练

class Solution {
public:
int minDistance(string word1, string word2) {
	int row = word1.size();
	int col = word2.size();
	if (row == 0 && col == 0)
		return 0;
	if (row == 0)
		return col;
	if (col == 0)
		return row;
	vector<vector<int>> index(row + 1, vector<int>(col + 1, 0));

	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<col; j++)
		{
			index[i + 1][j + 1] = std::max(index[i+1][j], index[i][j+1]);
			if (word1[i] == word2[j])
				index[i + 1][j + 1]= index[i][j]+1;
		}
	}
	int output = row - index[row][col] + col - index[row][col];
	return output;
}
};