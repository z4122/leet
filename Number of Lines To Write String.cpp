class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> temp;
        int first = 1,second = 0;
        for(auto val:S)
        {
            if(second + widths[val-'a']>100){
                second = 0;
                first+=1;
            }
            second+=widths[val-'a'];         
        }
        temp.push_back(first);
        temp.push_back(second);
        return temp;
    }
};