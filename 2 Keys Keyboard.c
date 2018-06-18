class Solution {
public:
    int minSteps(int n) {
        int numA = 1;
        int step = 1;
        bool copy = 0;
        int copy_num = 1;
        if(n==1)
            return 0;
        while(n>numA)
        {
            if((n%numA)!=0)    
            {
                if((n-numA)%copy_num==0)
                {
                    numA+=copy_num;
                    step++;
                }
                else
                {
                    numA++;
                    step++;
                }
                
            }
            else if((n%numA)==0&&copy == 1)
            {
                step++;
                copy = 0;
                copy_num = numA;
            }
            else if((n%numA)==0&&copy == 0)
            {
                step++;
                numA*=2;
                copy = 1;
            }
                
            
        }
        return step;
    }
};