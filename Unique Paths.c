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