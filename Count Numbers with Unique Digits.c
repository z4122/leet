class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int temp = 9;
        int output = 10;
        int time = 9;
        if(n==0)
            return 1;
        if(n==1)
            return 10;
        while(n!=1)
        {
            n--;
            temp *= time;
            time--;
            output += temp; 
        }
        return output;
    }
};