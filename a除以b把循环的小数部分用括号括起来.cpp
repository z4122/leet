
a/b问题，如果无限循环，把循环的小数部分用括号括起来
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int a = 0, b = 0;
	cin >> a;
	cin >> b;
	int result = 0;
	result = a / b;
	a = (a - b * result) * 10;
	if (a == 0) {
		cout << result;
		return 0;
	}
    cout << result;
	map<int, int>m;
	vector<int> temp;
	int position = 1;
	while (a != 0) {
		temp.push_back(result);
		result = a / b;
		a = (a - b * result) * 10;
		if (m.find(a) != m.end()) {
			break;
		}
		m.insert(make_pair(a, position++));
	}
	
	cout << '.';
	if (a == 0) {
		for (int i = 0; i<temp.size(); i++) {
			cout << temp[i];
		}
		return 0;
	}

	for (int i = 1; i<m.find(a)->second; i++) {
		cout << temp[i];
	}
	cout << '(';
	for (int i = m.find(a)->second; i<temp.size(); i++) {
		cout << temp[i];
	}
	cout << ')';

	return 0;

}