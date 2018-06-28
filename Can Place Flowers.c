class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int temp = 0;
        for(int i = 0;i<flowerbed.size();)
        {
            if(flowerbed[i]==0)
                if(flowerbed[i-1]==0&&(flowerbed[i+1]==0||i==flowerbed.size()-1))
                {
                    i+=2;
                    temp++;
                }
                else
                    i++;
            else
                i+=2;
        }
        if(temp>=n)
            return true;
        return false;
    }
};