int GetUglyNumber(int index)
{
    vector<int>uglynumber;
    uglynumber.push_back(1);
    int num = 0;
    int a[3] = {2,3,5};
    while(num!=index)
    {
        for(int i = 0;i<3;i++)
            ugly.push_back(uglynumber[num]*a[i]);
        num++;
    }
    return uglynumber[num];
}