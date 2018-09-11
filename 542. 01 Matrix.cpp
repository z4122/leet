542. 01 Matrix


Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.


//超时的解法
int compute(int x, int y, vector<vector<int>> matrix)
{
	pair<int, int>temp;
	int t1 = x;
	int t2 = y;
	queue<pair<int, int>> coordinate;
	coordinate.push(make_pair(x, y));

	while (coordinate.empty() == 0) {
		temp = coordinate.front();
		coordinate.pop();
		x = temp.first;
		y = temp.second;
		if (matrix[x][y] == 0)
			return abs(x - t1) + abs(y - t2);
		matrix[x][y] = 999;
		if (y - 1 >= 0 && matrix[x][y - 1] != 999) coordinate.push(make_pair(x, y - 1));		
		if (y + 1<matrix[0].size() && matrix[x][y + 1] != 999) coordinate.push(make_pair(x, y + 1));
		if (x - 1 >= 0 && matrix[x - 1][y] != 999) coordinate.push(make_pair(x - 1, y));	
		if (x + 1 < matrix.size() && matrix[x + 1][y] != 999) coordinate.push(make_pair(x + 1, y));				
	}
}

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
	int i = matrix.size();
	int j = matrix[0].size();
	vector<vector<int>> output(i, vector<int>(j, 0));

	for (int x = 0; x<i; x++)
		for (int y = 0; y<j; y++)
		{
			output[x][y] = compute(x, y, matrix);
		}
	return output;

}


//更好的解法
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
	int i = matrix.size();
	int j = matrix[0].size();
	vector<vector<int>> output(i, vector<int>(j, 0));
	pair<int, int>temp;
	queue<pair<int, int>> coordinate;
	for (int x = 0; x<i; x++)
		for (int y = 0; y<j; y++)
		{
			if (matrix[x][y] == 0) {
				coordinate.push(make_pair(x, y));
				output[x][y] = 0;
			}
			else {
				output[x][y] = 999;
			}

		}

	while (coordinate.empty() == 0) {
		temp = coordinate.front();
		coordinate.pop();
		int x = temp.first;
		int y = temp.second;
		matrix[x][y] = -1;

		if (y - 1 >= 0 && matrix[x][y - 1] != -1) {
			output[x][y - 1] = min(output[x][y] + 1, output[x][y - 1]);
			coordinate.push(make_pair(x, y - 1));
		}
		if (y + 1<matrix[0].size() && matrix[x][y + 1] != -1) {
			output[x][y + 1] = min(output[x][y] + 1, output[x][y + 1]);
			coordinate.push(make_pair(x, y + 1));
		}
		if (x - 1 >= 0 && matrix[x - 1][y] != -1) {
			output[x-1][y] = min(output[x][y] + 1, output[x - 1][y]);
			coordinate.push(make_pair(x - 1, y));
		}
		if (x + 1 < matrix.size() && matrix[x + 1][y] != -1) {
			output[x+1][y] = min(output[x][y] + 1, output[x + 1][y]);
			coordinate.push(make_pair(x + 1, y));
		}
	}

	return output;

}