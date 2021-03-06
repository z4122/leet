886. Possible Bipartition

染色块问题
每个人都有自己讨厌的人，如何把人群分成没有讨厌关系的两组，采用染色块的解法。只有两种颜色，不断的染色，只要有冲突则不行


Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Note:

1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].

class Solution {
public:    
unordered_map<int, vector<int>> people;


bool Dfs(vector<int>& index, int num, int color)
{
	if (index[num] == -1)
		index[num] = color;
	else
		return index[num]==color;
	for (int j = 0; j<people[num].size(); j++)
	{
		if (Dfs(index, people[num][j], 1 - color) == false)
			return false;
	}

	return true;
}

bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
	vector<int> index(N + 1, -1);
	if (dislikes.size() == 0)
		return true;
	for (int i = 0; i<dislikes.size(); i++)
	{
		people[dislikes[i][0]].push_back(dislikes[i][1]);
		people[dislikes[i][1]].push_back(dislikes[i][0]);
	}

	for (int i = 1; i <= N; i++)
	{
		if (index[i] == -1) {
			if (Dfs(index, i, 1) == false)
				return false;
		}
		else {
			if (Dfs(index, i, index[i]) == false)
				return false;
		}
	}

	return true;

}
};