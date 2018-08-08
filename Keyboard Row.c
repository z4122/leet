class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char,int>first;
        vector<string>output;
        
        string a = "qwertyuiopQWERTYUIOP",b = "asdfghjklASDFGHJKL",c = "zxcvbnmZXCVBNM";
        for(auto val:a)
            first[val] = 1;
        for(auto val:b)
            first[val] = 2;
        for(auto val:c)
            first[val] = 3;
        for(auto s:words)
        {
            int temp = first[s[0]];
            int i = 0;
            for(;i<s.length();i++)
            {
                if(temp==first[s[i]])
                    continue;     
                else
                    break;
            }
            if(i==s.size())
                output.push_back(s);
        }
        return output;
    }
};