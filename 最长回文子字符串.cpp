
//有两种比较好的解法

//解法一：动态规划的方法


string find(string input)
{
    vector<vector<int>> dp = {input.size()-1,vector<int>(input.size()-1,0)}; //dp[i][j]代表从i到j的最大回文子字符串的长度

    int left = 0;
    int maxlen = 0;

    for(int k = 0;k<input.size();k++)
    {
        dp[k][k] = 1;//对于每一个字符都可以当作长度为1的回文字符串
    }

    for(int k = 0;k<input.size()-1;k++)
    {
        if(input[k]==input[k+1])
            {
                dp[k][k+1] = 1;
                left = k;
                maxlen = 2; 
            }
    }

    for(int len = 2;len<=input.size();len++)
        for(int i = 0;i<=input.size()-len;i++)
        {
            int j = i+len-1;//i为最左边的坐标，j为最右边的坐标

            if(dp[i+1][j-1]&&input[i]==input[j])
            {
                dp[i][j] = 1;
                left = i;
                maxlen = len;
            }

        }

    return input.substr(left,left+manlen);
}

//解法二：从中心开始算起