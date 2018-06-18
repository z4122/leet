class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold = -prices[0],empty = 0;
        for(int i = 0;i<prices.size();i++)
        {
            hold = max(empty-prices[i],hold);
            empty = max(hold+prices[i]-fee,empty);
        }
        return empty;
    }
};

//首先要找出最优子结构和状态转移方程