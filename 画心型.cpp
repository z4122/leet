string temp = "- - - - - - - - - -";
	vector<string> coordinate(10, temp);
	int width = a[3] - a[1];
	int height = width/2+1;
	if (width % 2 == 0) 
		width += 1;
	int current_h = a[0]+1;
	int current_w = a[1];

	coordinate[a[0]][a[1]*2-2] = '#';
	coordinate[a[2]][a[3]*2-2] = '#';

	while (current_h < a[0] + height)
	{
		for (int i = a[1] - (current_h-a[0]); i < a[1] + (current_h - a[0])+1; i++)
			coordinate[current_h][i*2-2] = '#';
		current_h++;
	}

	current_h = a[2]+1;
	current_w = a[3];

	while (current_h < a[2] + height)
	{
		for (int i = a[3] - (current_h-a[2]); i < a[3] + (current_h - a[2])+1; i++)
			coordinate[current_h][i*2-2] = '#';
		current_h++;
	}
	
	int y = height+current_h;
	int x = (a[1] + a[3])/2;
	coordinate[y][x * 2 - 2] = '#';
	current_h = y - 1;
	
	while (current_h>y-height-1)
	{
		for (int i = x - (y-current_h); i < x + (y-current_h) + 1; i++)
			coordinate[current_h][i * 2 - 2] = '#';
		current_h--;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			printf("%c", coordinate[i][j]);
		}
		printf("\n");
	}
	
	
	
	string temp = "- - - - - - - - - -";
	vector<string> coordinate(10, temp);
	int iseven = 0;
	int height = a[3] - a[1]-1;
	int width = height;
	if (width % 2 != 0)
		iseven = 1;
	pair<int, int> first(a[1], a[0]),second(a[3],a[2]);
	
	pair<int, int>third(a[1] + width, a[0] + height), forth(a[1] + width, a[0] + height);

	pair<int, int> fifth(a[1] - width, a[0] + height), sixth(a[3] + width, a[2] + height);

	if (iseven)
		sixth.first += 1;
	
	pair<int, int>seventh((a[1]+a[3])/2,a[0]+2*height+3), eigth((a[1] + a[3]) / 2, a[0] + 2 * height + 3);

	if (iseven)
		eigth.first += 1;

	printtran1(coordinate,first,third,forth);
	printtran1(coordinate,second, fifth, sixth);

	printtran2(coordinate,third, sixth, seventh);
	printtran2(coordinate,third, sixth, eigth);
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			printf("%c", coordinate[i][j]);
		}
		printf("\n");
	}