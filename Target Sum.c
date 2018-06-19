class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        map<int,int> pre,now;
        pre[0] = 1;
        for(auto val:nums)
        {
            for(int i = -1000;i<1001;i++)
            {
                now[i] = pre[i-val]+pre[i+val];                
            }
            pre = now;
        }
        return now[S];
    }
};