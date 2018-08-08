class Solution {
public:
    int binaryGap(int N) {
        vector<int>temp,temp1;
        int output = 0,cnt = 0,first = 0;
        while(N)
        {
            temp.push_back(N%2);
            N = N/2;
        }
        for(int i = 0;i<temp.size();i++)
        {
            
            if(temp[i]==1)
                temp1.push_back(i);
        }
        for(int i = 1;i<temp1.size();i++)
            output = max(output,temp1[i]-temp1[i-1]);
        return output;
    }
};