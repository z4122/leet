659.分割数组为连续子序列

贪心算法，同时注意子序列的数量可以为1
输入一个按升序排序的整数数组（可能包含重复数字），你需要将它们分割成几个子序列，其中每个子序列至少包含三个连续整数。返回你是否能做出这样的分割？

 

示例 1：

输入: [1,2,3,3,4,5]
输出: True
解释:
你可以分割出这样两个连续子序列 : 
1, 2, 3
3, 4, 5
 

示例 2：

输入: [1,2,3,3,4,4,5,5]
输出: True
解释:
你可以分割出这样两个连续子序列 : 
1, 2, 3, 4, 5
3, 4, 5
 

示例 3：

输入: [1,2,3,4,4,5]
输出: False
 

提示：

输入的数组长度范围为 [1, 10000]


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>fre,tail;
        if(nums.size()<3)
            return false;
        for(auto val:nums){
            fre[val]++;
        }
        
        for(auto val:nums){
            if(fre[val]==0) continue;
            
            fre[val]--;
            
            if(tail[val-1]!=0){
                tail[val-1]--;
                tail[val]++;   
            }
            else if(fre[val+1]&&fre[val+2]){
                fre[val+1]--;
                fre[val+2]--;
                tail[val+2]++;
            }
            else
                return false;
        }
        return true;
    }
};