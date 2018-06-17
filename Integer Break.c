class Solution {
public:
    int integerBreak(int n) {
        int temp = 2;
        int output = 2;
        int num2 = 1;
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        while(temp<n)
        {
            if(num2 == 1)
            {
                num2 = 0;
                output = output/2*3;
                temp++;
                continue;
            }
            if(num2 == 0)
            {
                num2 = 2;
                output = output/3*4;
                temp++;
                continue;
            }
            if(num2 == 2)
            {
                num2 = 1;
                output = output/2*3;
                temp++;
                continue;
            }

           
        }
        return output;
    }
};