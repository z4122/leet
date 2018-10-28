406.根据身高重建队列

贪心

假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]



static bool compare2(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first)
		return p1.second < p2.second;
	else
		return p1.first > p2.first;
}

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
	vector<pair<int, int>> res;
	sort(people.begin(), people.end(), compare2);
	for (int i = 0; i < people.size(); ++i) {
		res.insert(res.begin() + people[i].second, people[i]);
	}
	return res;
}

class Solution {
public:
    
    static bool comp(pair<int,int>a,pair<int,int>b){
        if(a.first<b.first)
            return true;
        else if(a.first==b.first){
            if(a.second<b.second)
                return true;
        }
        return false;
    }
    
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(),people.end(),comp);
        
        vector<pair<int,int>> result(people.size());
        
        for(auto val:people){
            for(int i = 0,j = 0;i<people.size()&&j<=val.second;){
                if(j==val.second&&result[i].first==-1){
                    result[i] = val;
                    break;   
                }
                if(result[i].first==-1){
                    j++;
                    i++;
                }
                else if(result[i].first==val.first){
                    i++;
                    j++;
                }
                else
                    i++;
            }
        }
        return result;
    }
};