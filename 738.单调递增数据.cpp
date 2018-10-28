738.单调递增数据



给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。

（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）

示例 1:

输入: N = 10
输出: 9
示例 2:

输入: N = 1234
输出: 1234
示例 3:

输入: N = 332
输出: 299
说明: N 是在 [0, 10^9] 范围内的一个整数。

class Solution {
public:
    
bool recur(int &sum, int N, int size, int len, int last) {
	if (sum <= N && len == 0)
		return sum;
	if (sum > N)
		return false;
	for (int i = 9; i >= 0; i--) {
		if (i<last)
			return false;
		sum += (size*i);
		if (recur(sum, N, size/10, len-1,i))
			return sum;
		sum -= (size*i);
	}

	return false;

}

int monotoneIncreasingDigits(int N) {
	int len = 0;
	int i = 1;
	while (i <= N) {
		i *= 10;
		len++;
	}
	i /= 10;
	int sum = 0;

	for (int m = N / i; m >= 1; m--) {
		sum = m * i;
		if (recur(sum, N, i / 10, len - 1, m))
			return max(sum, N / i * i - 1);

	}

	sum = N / i * i - 1;
	return sum;

}

    
};