class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> output;
        vector<int> temp;        

        int r_s = nums.size();
        int c_s = nums[0].size();
        
        if(r*c>r_s*c_s)
            return nums;
        
        int c_temp = 0;
        for(int i = 0;i<r_s;i++)
        {
            for(int j = 0;j<c_s;j++)
            {
                temp.push_back(nums[i][j]);
                c_temp++;
                if(c_temp==c)
                {
                    output.push_back(temp);
                    temp.clear();
                    c_temp = 0;
                }
            }
        }
        return output;
    }
};