class Solution {
public:
    int compute(string s,int begin,int end)
    {
        
        int temp = 0;
        while((begin>=0)&&(end<=s.length()-1)&&(s.at(begin)==s.at(end)))
        {
            temp++;
            begin--;
            end++;
        }
        return temp;
    }
    
    int countSubstrings(string s) {
        int count = 1;
        for(int i = 0;i<s.length()-1;i++)
        {
            count+=compute(s,i,i);
            count+=compute(s,i,i+1);
                
        }
        return count;
    }
    
    
    
};