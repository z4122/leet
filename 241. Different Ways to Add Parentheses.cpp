241. Different Ways to Add Parentheses
DescriptionHintsSubmissions



Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1:

Input: "2-1-1"
Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: "2*3-4*5"
Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10


class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        for(int i = 0;i<input.size();i++)
        {
            
            if(input[i]>='0'&&input[i]<='9')
            {
                
            }
            else
            {
                vector<int>left = diffWaysToCompute(input.substr(0,i));
                vector<int>right = diffWaysToCompute(input.substr(i+1,input.size()-i-1));
                switch(input[i]){
                    case '*':
                        for(int m = 0;m<left.size();m++)
                            for(int n = 0;n<right.size();n++)
                            {
                                ret.push_back(left[m]*right[n]);
                            }
                        break;
                    case '+':
                         for(int m = 0;m<left.size();m++)
                            for(int n = 0;n<right.size();n++)
                            {
                                ret.push_back(left[m]+right[n]);
                            }
                        break;
                    case '-':
                        for(int m = 0;m<left.size();m++)
                            for(int n = 0;n<right.size();n++)
                            {
                                ret.push_back(left[m]-right[n]);
                            }
                        break;
                }
                
            }
        }
        if(ret.size()==0){
            stringstream s(input);
            int temp;
            s>>temp;
            ret.push_back(temp);
        }
        return ret;
    }
};