class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.size()-1,j = T.size()-1;
        int icnt = 0,jcnt = 0;
        while(i>-1||j>-1)
        {
            if(i>=0){
            if(S[i]=='#'){
                icnt++;
                i--;
                continue;
            }
            if(icnt){
                S[i] = ' ';
                i--;
                icnt--;
                continue;
            }
            }
            if(j>=0){
            if(T[j]=='#'){
                jcnt++;
                j--;
                continue;
            }
            if(jcnt){
                T[j] = ' ';
                j--;
                jcnt--;
                continue;
            }
            }
            if(S[i]==T[j]){
                i--;
                j--;
            }
            else
                return false;
        }
        return true;
    }
};