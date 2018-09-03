class Solution {
public:
    
    string recur(string s,int& k)
    {
        int cnt = 0;
        string temp;
        string output;
        for(;k<s.size();)
        {
            if(s[k]>='0'&&s[k]<='9')
            {
                cnt = cnt*10+s[k]-'0';
                k++;
                continue;
            }          
            else if(s[k] == '[')
            {
                k++;
                temp = recur(s,k);
                while(cnt--)
                {
                    output+=temp;                    
                }
                cnt=0;
            }
            else if(s[k] == ']')
            {
                k++;
                return output;
            }
            else
            {
                output+=s[k];
                k++;
            }
            
        }
        return output;
    }
    
    string decodeString(string s) {
        int k = 0;
        return recur(s,k);
    }
};