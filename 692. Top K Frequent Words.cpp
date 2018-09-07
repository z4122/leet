692. Top K Frequent Words

Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.

class Solution {
public:
    
    
    static bool comp(pair<string,int> first,pair<string,int>second)
    {
        int n = 0;
        if(first.second==second.second){
            while(first.first[n]==second.first[n])
                n++;
            if(first.first[n]<second.first[n])
                return 1;
            else
                return 0;
        }
        if((first.second)>(second.second))
            return 1;
        else 
            return 0;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> temp;
        vector<string> output;
        for(auto val:words)
            temp[val]++;
        
        vector<pair<string,int>> sortstring(temp.begin(),temp.end());
        
        sort(sortstring.begin(),sortstring.end(),comp);
    
        for(int i = 0;i<k;i++)
        {
            output.push_back(sortstring[i].first);
        }
        
        return output;
    }
    
    
};