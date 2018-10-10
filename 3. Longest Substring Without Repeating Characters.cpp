
3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring. 



 int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        if(s.size()==1)
            return 1;  
        unordered_map<char,pair<int,int>> index;

        int output = 0;
        int ret = 0;
        int repet = 0;
        for(auto c:s)
            index[c].first = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(index[s[i]].first==0){
                index[s[i]].first=1;
                index[s[i]].second = i;
                output++;
            }
            else{
                ret = max(output,ret);
                output = i-max(repet,index[s[i]].second);
                repet = max(repet,index[s[i]].second);
                index[s[i]].second = i;
                ret = max(output,ret);
            }
        }
        ret = max(output,ret);
        return ret;
    }
	
	
//不如这种解法好
	class Solution {
public:
bool visited[200];
int pre[200];
    int lengthOfLongestSubstring(string s) {
        int begin=0,end=-1;
        int ans=0;
        while(end+1<s.length()){
            end++;
            int cur = s[end];
            if(visited[cur]){
            //printf("bf: %d %d\n",begin,end);
                begin = max(begin,pre[cur]+1);
            //printf("at: %d %d\n",begin,end);
            }
            ans = max(ans,end-begin+1);
            //printf("ans: %d\n",ans);
            visited[cur]=1;
            pre[cur]=end;
        }
        return ans;
    }
};