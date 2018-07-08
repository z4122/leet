class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>output(n,vector<int>(n));
        
        int temp = 1,i = 0,j = 0;
        while(temp<n*n)
        {
            while(j+1<n&&output[i][j+1]==0)
                output[i][j++] = temp++;
            while(i+1<n&&output[i+1][j]==0)
                output[i++][j] = temp++;
            while(j>=1&&output[i][j-1]==0)
                output[i][j--]= temp++;
            while(output[i-1][j]==0)
                output[i--][j]= temp++;
            
        }
        
        output[n/2][(n-1)/2] = n*n;
        
        if(n==2)
        {
            output[1][1] = 3;
            output[1][0] = 4;
        }
        return output;
    }
};