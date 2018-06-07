class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> output(num+1,0);
        int temp = 1;
        output[0] = 0;
        for(int i = 1;i<num+1;i++)
        {
            while(i>=temp*2)
                temp *= 2;
            output[i] = output[i - temp]+1;
        }
        return output;
            
    }
};