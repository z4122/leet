class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if(rooms.size()==0)
            return false;
        stack<int> roomnumber;
        vector<int> index(rooms.size(),0);
        index[0] = 1;
        roomnumber.push(0);
        while(!roomnumber.empty())
        {
            int temp = roomnumber.top();
            roomnumber.pop();
            for(auto val:rooms[temp])
            {
                if(index[val]==0)
                {
                    index[val]=1;
                    roomnumber.push(val);
                }
            }            
        }
        for(auto val:index)
        {
            if(val==0)
                return false;
        }
        return true;
    }
};