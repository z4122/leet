class Solution {
public:    
    
    static bool comp(pair<char, int> fir, pair<char, int>sec) {
	return fir.second > sec.second;
}
string reorganizeString(string S) {
	if (S.size() <= 1)
		return "";
	map<char, int>index;
	string output;
    char last = ' ';
	for (auto val : S)
	{
		index[val]++;
	}

	vector<pair<char, int>> orderedIndex(index.begin(), index.end());
	sort(orderedIndex.begin(), orderedIndex.end(), comp);

    if(S.size()%2==0){
	    if (orderedIndex[0].second > S.size() / 2)
		    return "";
    }
    else{
        if (orderedIndex[0].second > S.size() / 2+1)
		    return "";
    }
    int i = 0;
	while(orderedIndex[0].second!=0){
        if(orderedIndex[i].first!=last){
            last = orderedIndex[i].first;
            output+=last;
            orderedIndex[i].second--;
            sort(orderedIndex.begin(), orderedIndex.end(), comp);
            i=0;
        }
        else
        {
            i++;
        }		
	}
	return output;
}
        
        
    
};