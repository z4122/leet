LeetCode 524. 通过删除字母匹配到字典里最长单词

Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
Note:
All the strings in the input will only contain lower-case letters.
The size of the dictionary won't exceed 1,000.
The length of all the strings in the input won't exceed 1,000.



class Solution {
public:
string findLongestWord(string s, vector<string>& d) {
	unordered_map<char, vector<int>>index;
	int maxlen = -1;
	string ret;
	for (int i = 0; i<s.size(); i++) {
		index[s[i]].push_back(i);
	}

	for (auto iter = index.begin(); iter != index.end(); iter++) {
		iter->second.push_back(0);
	}

	for (auto s : d)
	{
		int last = -1;
		unordered_map<char, vector<int>>temp = index;
		for (int j = 0; j<s.size(); j++) {
			if (temp.find(s[j]) != temp.end()) {
				int subscript = temp[s[j]].back();
				while (temp[s[j]][subscript] < last) {
					subscript++;
					if (subscript == temp[s[j]].size())
						break;
				}
				if (subscript == temp[s[j]].size())
					break;
				last = temp[s[j]][subscript];
				*(--temp[s[j]].end()) = subscript;

			}
			else
				break;

			if (j == s.size() - 1 && j>maxlen) {
				maxlen = j;
				ret = s;
			}
			if (j == s.size() - 1 && j == maxlen) {
				maxlen = j;
				if (ret>s)
					ret = s;
			}

		}
	}

	return ret;

}
};


class Solution {
public:  
    bool isWord(string pattern, string &srcStr){
        int i=0, j=0, pLen=int(pattern.size()), sLen=int(srcStr.size());
        while(i<pLen && j<sLen){
            if(pattern[i]==srcStr[j]){
                ++i;
                ++j;
            }
            else
                ++i;
        }
        
        if(j<sLen)
            return false;
        else
            return true;
    }    
   
    static bool compare(string &a, string &b){
        if(a.size()>b.size())
            return true;    
        else if(a.size()==b.size()){
            if(a<b)
                return true;
            else
                return false;
        }      
        else
            return false;
    }
  
    string findLongestWord(string s, vector<string>& d) {
        if(s.size()==0 || d.size()==0)
            return "";
                
        sort(d.begin(), d.end(), compare);
        
        for(int i=0;i<d.size();++i){
            if(isWord(s, d[i])){
                return d[i];
            }
        }
        
        return "";
    }
};
