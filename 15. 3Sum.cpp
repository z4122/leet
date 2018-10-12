15. 3Sum

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        unordered_map<int,int>index;
        vector<vector<int>> output;
        
        if(nums.size()<=2)
            return output;
            
        for(int i = 0;i<nums.size();i++)
        {
            index[nums[i]]++;
        }
        
        int first_last = INT_MIN,second_last = INT_MIN;
        for(int i = 0;i<nums.size()-2;i++){
            int first = nums[i];
            if(first==first_last)
                continue;
            index[first]--;
            for(int j = i+1;j<nums.size()-1;j++){
                int second = nums[j];
                if(second_last==second)
                    continue;
                index[second]--;
                if(-second-first>=second)
                    if(index.find(-second-first)!=index.end()&&index[-second-first]!=0){
                        vector<int> temp;
                        temp.push_back(first);
                        temp.push_back(second);
                        temp.push_back(-second-first);
                        output.push_back(temp);
                    }
                index[second]++;
                second_last = second;
            }
            index[first]++;
            first_last = first;
        }
        return output;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> result;
        
        if (nums.size() < 3) return result;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int cur = nums[i];
            if (cur > 0)
            {
                // start with greater than zero = not possible
                break;
            }
            
            if (i > 0 && cur == nums[i - 1])
            {
                // skip over same element, cant add up to zero
                continue;
            }
            
            // now check from current element to the remaining greater ones. current one is <= 0
            int j = i + 1; // elem next to current
            int k = nums.size() - 1; // last elem
            while (j < k)
            {
                int tempJ = nums[j];
                int tempK = nums[k];
                
                int val = tempJ + tempK + cur;
                if (val == 0)
                {
                    result.push_back(vector<int>({cur, nums[j], nums[k]}));
                    
                    // skip over remaining similar elements
                    while (j < k && nums[j] == tempJ) j++;
                    while (j < k && nums[k] == tempK) k--;
                }
                else if (val > 0)
                {
                    // too big
                    k--;
                }
                else
                {
                    // too small
                    j++;
                }
            }
        }
        
        return result;
    }
};