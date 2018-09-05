class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        map<int,int> temp;
        for(auto val:candies)
        {
            temp[val]++;
        }
        if(temp.size()>candies.size()/2)
            return candies.size()/2;
        else
            return temp.size();
    }
};