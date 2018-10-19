 
//例程更好
 string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1,
            j = b.size() - 1,
            c = 0;
        while (i >= 0 || j >= 0 || c > 0) {
            c += (i >= 0 ? a[i--] - '0' : 0);
            c += (j >= 0 ? b[j--] - '0' : 0);
            res = (char) (c % 2 + '0') + res;
            c /= 2;
        }
        return res;
    }
	
	
	class Solution {
public:
    string addBinary(string a, string b) {
        int maxlen = max(a.size(),b.size());
        
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ret;
        
        int temp = 0;
        int sum = 0;
        for(int i = 0;i<maxlen;i++)
        {            
            if(a.size()<=i)  sum = b[i]-'0'+temp;
            else if(b.size()<=i) sum = a[i]-'0'+temp;
            else sum = (a[i]-'0')+(b[i]-'0')+temp;
                    
            if(sum==2){
                temp = 1;
                ret+="0";  
            }
            else if(sum==3){
                temp = 1;
                ret+='1';
            }
            else{
                temp = 0;
                ret+=(sum+'0');                
            }                           
        }
        if(temp==1)
            ret+='1';
        reverse(ret.begin(),ret.end());
        return ret;
    }
};