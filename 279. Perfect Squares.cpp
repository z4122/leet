279. Perfect Squares
不应该用dp二维数组   


   int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        dp[4] = 1;
        dp[9] = 1;
        for(int i = 5;i<n+1;i++)
        {
            int j = 1;
            while(j*j<=i)
            {
                if(dp[i]>1+dp[i-j*j])
                    dp[i] = 1+dp[i-j*j];
                j++;
            }
        }
        return dp[n];
    }