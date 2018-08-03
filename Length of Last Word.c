class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int flag = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                flag = 1;              
            }
            else if(s[i]!=' '&&flag==1)
            {
                cnt = 1;
                flag = 0;
            }
            else
            {
                cnt++;
            }
        }
        return cnt;
    }
};