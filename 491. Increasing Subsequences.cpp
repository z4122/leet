
491. Increasing Subsequences

Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.



Vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res; // use set to filter same solution
        vector<int> tmp; // a solution item
        dfs(nums, res, tmp, 0);
        return vector<vector<int>> (res.begin(), res.end());
    }


    void dfs(vector<int>& nums, set<vector<int>>& res, vector<int> tmp, int k) {

        /*
            k: start index for DFS
         */

        if (tmp.size() >= 2) res.insert(tmp);

        for (int i = k; i < nums.size(); ++i) {
            // append element into tmp when it is empty 
            // or the new element is not less then the last element
            if (tmp.size() == 0 || nums[i] >= tmp.back()) {
                tmp.push_back(nums[i]);
                dfs(nums, res, tmp, i+1); //iteratively dfs among the remaining elements
                tmp.pop_back(); 
            }
        }
    }

---------------------

本文来自 yang蜗牛 的CSDN 博客 ，全文地址请点击：https://blog.csdn.net/juanqinyang/article/details/63686262?utm_source=copy 



class Solution {
public:    
    vector<vector<int>> Dfs(vector<int> nums)
    {
        vector<vector<int>> dfs,ret;
        
        if (nums.size() == 1)
	    {
		    ret.push_back(vector<int>(1, nums[0]));
		    ret.push_back(vector<int>());
		    return ret;
	    }
        
        dfs = Dfs(vector<int>(nums.begin()+1,nums.end()));
        
        for(int i = 0;i<dfs.size();i++)
        {
            if(dfs[i].size()==0){
                ret.push_back(dfs[i]);
                dfs[i].insert(dfs[i].begin(),nums[0]);
                ret.push_back(dfs[i]);
                continue;
            }  
            
            if(nums[0]<=dfs[i][0]){
                ret.push_back(dfs[i]);
                dfs[i].insert(dfs[i].begin(),nums[0]);
                ret.push_back(dfs[i]);
                continue;
            }
        }
        return ret;
    }
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ret;
        set<vector<int>> output;
        if(nums.size()==0)
            return ret;
        ret = Dfs(nums);
        
        for(int i = 0;i<ret.size();i++)
        {
            if(ret[i].size()>1)
                output.insert(ret[i]);
        }
        return vector<vector<int>> (output.begin(),output.end());
    }
};