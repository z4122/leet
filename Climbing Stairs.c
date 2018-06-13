int climbStairs(int n) {
    int index = 1;
    int num_even = 0,num_odd = 1;
    int temp = num_odd;
    if(n == 0)
        return 0;
    while(index<n)
    {
        index++;
        temp = num_odd;
        num_odd = num_even+num_odd;
        num_even = temp;
    }
        
    return num_even+num_odd;
        
        
    }