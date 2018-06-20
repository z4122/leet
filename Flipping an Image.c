class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int len = A.size();
        if(len==0)
            return A;
        vector<int> temp(len);
        for(int i = 0;i<len;i++)
        {
            for(int j = 0;j<len;j++)
                temp[len-j-1] = A[i][j];
            for(int j = 0;j<len;j++)
                A[i][j] = temp[j];
            for(int j = 0;j<len;j++)
                A[i][j] = !A[i][j];
        }
        return A;
    }
};