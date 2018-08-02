class Solution {
public:
    bool isValid(string s) {
        vector<char>temp;
        for(int i = 0;i<s.size();i++)
        {
           switch(s[i])
           {
               case '(':{}
               case '[':{}
               case '{':{temp.push_back(s[i]);break;}
               case ')':
                   {
                        if(temp.empty())
                            return false;
                        if(temp.back()=='(')
                            temp.pop_back();
                        else 
                           return false;
                        break;
                   }
               case ']':
                   {
                                               if(temp.empty())
                            return false;
                       if(temp.back()=='[')
                           temp.pop_back();
                       else 
                           return false;
                       break;
                   }
                case '}':
                   {
                                               if(temp.empty())
                            return false;
                       if(temp.back()=='{')
                            temp.pop_back();
                       else
                           return false;
                       break;
                       
                   }
               default:
                   break;                                
           }
        }
        if(temp.empty())
            return true;
        else
            return false;
        
    }
};