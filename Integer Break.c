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


//上面这个解法不好，规律找的一般
{
	while(n>4)
	{
		n-=3;
		temp*=3;
	}
	
	//最后剩下的一定是2或4.
}

{
	//另外也可以用动态规划的方法。
	//每一个数是前面第三个数的三倍。暗含规律多了一个三
}
