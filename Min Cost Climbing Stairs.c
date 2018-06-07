class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int output = 0;
        int index = 2;
        vector<int> temp;
        
        if(cost.size()==1)
            return cost[0];
        
        temp.push_back(cost[0]);
        temp.push_back(cost[1]);
        
        while(index<cost.size())
        {
            temp.push_back(min(temp[index-1],temp[index-2])+cost[index]);
            index++;
        }
        
        return min(temp[index-1],temp[index-2]);
    }
};