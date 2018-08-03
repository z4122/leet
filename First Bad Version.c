// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int left = 1,right = n;
        if(isBadVersion(1))
            return 1;
        while(1)
        {
            if(isBadVersion((right+left)/2))
                right = (right+left)/2;
            else
                left = (right+left)/2;
            
            if((right-left)==1)
            {
                return right;
            }
        }
    }
};