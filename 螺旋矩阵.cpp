vector<vector<int>> matrix(5, vector<int>(7, 0));
	int i = 0, j = 0;
	int iend = 4, istart = 0;
	int jend = 6, jstart = 0;
	
	while (matrix[i][j] != 1)
	{
		while (j < jend&&matrix[i][j]==0)
			matrix[i][j++] = 1;
		jend--;
		while (i < iend&&matrix[i][j] == 0)
			matrix[i++][j] = 1;
		iend--;
		while (j > jstart&&matrix[i][j] == 0)
			matrix[i][j--] = 1;
		jstart++;
		while (i > istart&&matrix[i][j] == 0)
			matrix[i--][j] = 1;
		istart++;
		i++;
		j++;
	}
	matrix[i][j] = 1;