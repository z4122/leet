class Solution {
public:
    int uniquePaths(int m, int n) {
        int step = m+n-2;
        int a,b;
        long int output = 1;
        if(n<m)
        {
            a = n-1;
            b = a;
        }
        else
        {
            a = m-1;
            b = a;
        }
        
        if(a==0)
            return 1;
        
        while(b--)
        {
            output*=step--;
        }
        
        b = 1;
        while(a)
        {
            b *= a;
            a--;
        }
        
        output/=b;
        return output;
        
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<m;i++)
            dp[i][0] = 1;
        for(int j = 0;j<n;j++)
            dp[0][j] = 1;
        if(m==1||n==1)
            return 1;
            
        for(int i = 1;i<m;i++)
            for(int j = 1;j<n;j++)
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
        return dp[m-1][n-1];
    }
};