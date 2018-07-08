class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int length = A.size();
        int output = 0;
        vector<vector<int>> temp(2*length+1,vector<int>(2*length+1));
        for(int i_a = 0;i_a<length;i_a++)
            for(int i_b = 0;i_b<length;i_b++)
                if(A[i_a][i_b]==1)
                    for(int i_c = 0;i_c<length;i_c++)
                        for(int i_d = 0;i_d<length;i_d++)
                            if(B[i_c][i_d]==1)
                                temp[i_c-i_a+length-1][i_d-i_b+length-1]++;
        
        
        for(int i = 0;i<2*length+1;i++)
            for(int j = 0;j<2*length+1;j++)
                output = max(output,temp[i][j]);
        
        return output;
                            
    }
};