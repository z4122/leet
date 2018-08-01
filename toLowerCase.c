string toLowerCase(string str) {
	for (int i = 0;i<str.size();i++)
		if (str[i]<96)
			str[i] += 32;
	return str;
}