class Solution {
public:
    bool isHappy(int n) {
        vector<int> temp;
        int last = 0,now = 0;
        map<int,bool> redefine;
        while(n)
        {
            temp.push_back(n%10);
            n = n/10;
        }
        for(int val:temp)
            last += val*val;
        n = last;
        temp.clear();
        
        while(last!=now){
            last = now;
            if(redefine[last]==1)
                return false;
            else
                redefine[last]=1;
            while(n)
            {
                temp.push_back(n%10);
                n = n/10;
            }
            now = 0;
            for(int val:temp)
            {
                now+=val*val;
            }
            n = now;
            temp.clear();
        }
        if(now==1)
            return true;
        else
            return false;
    }
};