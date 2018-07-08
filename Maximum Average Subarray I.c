class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long int temp = 0;
        long int output = INT_MIN;
        for(int i = 0;i<k;i++)
            temp += nums[i];
        output = temp;
        for(int i = k;i<nums.size();i++)
        {  
            temp -= nums[i-k];
            temp += nums[i];
            output = max(output,temp);
        }

        return (double)output/k;
    }
};