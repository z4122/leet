//可以用string.split 和tolower

class Solution {
public:
    map<char,int>index;
    
    string toGoatLatin(string S) {
        if(S.size()==0)
            return NULL;
        index['a'] = 1;
        index['e'] = 1;
        index['i'] = 1;
        index['o'] = 1;
        index['u'] = 1;
        index['A'] = 1;
        index['E'] = 1;
        index['I'] = 1;
        index['O'] = 1;
        index['U'] = 1;
        string temp;
        string output;
        int cnt = 0;
        for(int j = 0;j<S.size()+1;j++)
        {
            if(j==S.size())
            {
                cnt++;
                if(index[temp[0]]){
                    temp.append("ma");
                    output.append(temp);   
                }
                else{
                    temp.append(&temp[0],1);
                    temp.append("ma");
                    output.append(++temp.begin(),temp.end());
                }
                
                for(int i = 0;i<cnt;i++)
                {
                    output.append("a");
                }
      
                
                temp.clear();
                break;
            }
                         
            if(S[j]!=' '){
                temp.append(&S[j],1);
            }
            else{
                cnt++;
                if(index[temp[0]]){
                    temp.append("ma");
                    output.append(temp);   
                }
                else{
                    temp.append(&temp[0],1);
                    temp.append("ma");
                    output.append(++temp.begin(),temp.end());
                }
                
                for(int i = 0;i<cnt;i++)
                {
                    output.append("a");
                }
                output.append(" ");
                
                temp.clear();
            }
        }
        return output;
    }
};