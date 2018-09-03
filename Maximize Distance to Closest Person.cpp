class Solution {
public:
    int computeleft(vector<int>& seats,int index)
    {
        int output = 0;
        if(index==0)
            return INT_MAX;
        while(index>=0&&seats[index--]==0)
            output++;
        return output;
    }
    
    int computeright(vector<int>& seats,int index)
    {
        int output = 0;
        if(index==seats.size()-1)
            return INT_MAX;
        while(index!=seats.size()&&seats[index++]==0)
            output++;
        
        return output;
    }
    
    int maxDistToClosest(vector<int>& seats) {
        vector<vector<int>> temp(seats.size(),vector<int>(2));
        int output = 0;
        for(int i = 0;i<seats.size();i++)
        {
            if(seats[i]==0){
                temp[i][0] = computeleft(seats,i);
                temp[i][1] = computeright(seats,i);
                output = max(output,temp[i][0]<temp[i][1]?temp[i][0]:temp[i][1]);
            }
        }
        return output;
    }
};