842.把字符串分割成斐波那契数列


给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列 [123, 456, 579]。

形式上，斐波那契式序列是一个非负整数列表 F，且满足：

0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）；
F.length >= 3；
对于所有的0 <= i < F.length - 2，都有 F[i] + F[i+1] = F[i+2] 成立。
另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。

返回从 S 拆分出来的所有斐波那契式的序列块，如果不能拆分则返回 []。

示例 1：

输入："123456579"
输出：[123,456,579]
示例 2：

输入: "11235813"
输出: [1,1,2,3,5,8,13]
示例 3：

输入: "112358130"
输出: []
解释: 这项任务无法完成。
示例 4：

输入："0123"
输出：[]
解释：每个块的数字不能以零开头，因此 "01"，"2"，"3" 不是有效答案。
示例 5：

输入: "1101111"
输出: [110, 1, 111]
解释: 输出 [11,0,11,11] 也同样被接受。
提示：

1 <= S.length <= 200
字符串 S 中只含有数字。

class Solution {
public:
bool dp(string& S, string first, string second, int start, vector<int>& ret) {
	if (start == S.size())
		return true;
	if (first[0] == '0'&&first.size() != 1)
		return false;
	if (second[0] == '0'&&second.size() != 1)
		return false;
    string strmax = to_string(INT_MAX);
	if (first.size()==10&&first > strmax)
		return false;
    if(second.size()==10&&second>strmax)
        return false;
	int ifirst = stoi(first);
	int isecond = stoi(second);
	long int temp = ifirst + isecond;
	if (temp>INT_MAX) {
		return false;
	}

	string third = to_string(temp);
	if (third == S.substr(start, third.size())) {
		if (dp(S, second, third, start + third.size(), ret)) {
			ret.insert(ret.begin(),temp);
			return true;
		}
	}
	else
		return false;

	return false;
}


vector<int> splitIntoFibonacci(string S) {
	vector<int> ret;
	for (int i = 1; i<S.size() && i<11; i++) {
		for (int j = 1; i + j<S.size() && j<11; j++) {
			if (dp(S, S.substr(0, i), S.substr(i, j), i + j, ret)) {
                ret.insert(ret.begin(),stoi(S.substr(i,j)));
                ret.insert(ret.begin(),stoi(S.substr(0,i)));
				return ret;
			}
		}

	}
	return ret;
}
};