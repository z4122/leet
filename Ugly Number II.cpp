class Solution {
public:   
    int nthUglyNumber(int n) {
        vector<int> index = {1};
        int two = 0,three = 0,five = 0;
        int minNum = 1;
        while(index.size()!=n)
        {
            minNum = min(index[two]*2,min(index[three]*3,index[five]*5));
            if(minNum==index[two]*2)   two++;
            if(minNum==index[three]*3) three++;
            if(minNum==index[five]*5)  five++;
            index.push_back(minNum);                    
        }
        return minNum;
    }
};