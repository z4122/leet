22.括号配对问题

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]


 vector<string> generateParenthesis(int n) {
        unordered_set<string> pass;
        int LN = n;
        int RN = n;
        string cur = "";
        formParenthesis(&pass, cur, LN, RN);
        vector<string> res(pass.begin(), pass.end());
        return res;
    }
    
    void formParenthesis(unordered_set<string>* pass, string cur,int LN, int RN) {
        if (LN == 0 && RN == 0) {
            pass->insert(cur);
            return;
        }
        
        if (RN - LN == 0) {
            //cur.append("(");
            formParenthesis(pass, cur+"(", LN-1, RN);
        } else if (RN - LN > 0) {
            if (RN > 0) {formParenthesis(pass, cur+")", LN, RN-1);}
            if (LN > 0 ) formParenthesis(pass, cur+"(", LN-1, RN);
        }
        return;
        
    }


class Solution {
public:
vector<string> recur(int n, int leftpar, int rightpar) {
	vector<string>ret;
	string temp;
	if (leftpar>rightpar)
		return ret;
	if (rightpar == 1&&leftpar==0) {
		temp = ")";
		ret.push_back(temp);
		return ret;
	}
	if (leftpar >0)
	{
		vector<string>left = recur(n, leftpar - 1, rightpar);
		for (int i = 0; i < left.size(); i++) {
			temp = "(";
			temp += left[i];
			ret.push_back(temp);
		}
	}
	if (rightpar > 0) {
		vector<string>right = recur(n, leftpar, rightpar - 1);
		for (int i = 0; i < right.size(); i++) {
			temp = ")";
			temp += right[i];
			ret.push_back(temp);
		}
	}

	return ret;
}

vector<string> generateParenthesis(int n) {
	vector<string>ret;
	ret = recur(n, n, n);
	return ret;
}
};