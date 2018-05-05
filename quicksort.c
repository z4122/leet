
void quicksort(int* input,int left,int right)//right�ǳ���-1���ӵ�������
{
	int key = input[left];
	int i = left, j = right;

	if (i >= j)
		return;

	while (i != j)
	{
		while ((input[j]>key)&&(j>i))
		{
			j--;
		}
		input[i] = input[j];
		while((input[i]<key)&&(i<j))
		{
			i++;
		}
		input[j] = input[i];
	} 

	input[i] = key;
	quicksort(input, left,i-1);
	quicksort(input, j+1,right);
}


void quicksort(int* input,int left,int right)//�Ӹ�������
{
    int key = input[left];
    int i = left,j = right;
    if(left>=right)
        return;
    while(i<j)
    {
        while((i<j)&&(key>input[j]))
            j--;
        input[i] = input[j];
        while((i<j)&&(key<input[i]))
            i++;
        input[j] = input[i];      
    }
    input[j] = key;
    
    quicksort(input,left,i-1);
    quicksort(input,j+1,right);
    
}