class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double s = 0,temp = 0;
        for(auto vala:points)
            for(auto valb:points)
                for(auto valc:points)
                {
                   temp = (1.0 / 2.0)*(vala[0] * valb[1] + valb[0] * valc[1] + valc[0] * vala[1] - vala[0] * valc[1] - valb[0] * vala[1] - valc[0] * valb[1]);
                    if(temp>s)
                        s = temp;
                }
       return s;
    }
};