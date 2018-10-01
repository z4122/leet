332. Reconstruct Itinerary
//若干张票，起点固定，找出使用完所有票的一条通路
//一开始用DFS超时了
//因此改用入度和出度的概念

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.


class Solution {
public:


vector<string> findItinerary(vector<pair<string, string>> tickets) {
	map<string, vector<string>> index;
	vector<string> ret;
	for (int i = 0; i<tickets.size(); i++)
	{
		index[tickets[i].first].push_back(tickets[i].second);
	}

	for (auto iter = index.begin(); iter != index.end(); iter++)
	{
		sort((*iter).second.begin(), (*iter).second.end());
	}

	stack<string> s;
    s.push("JFK");
    while(!s.empty())
    {
        string temp = s.top();
        if(index[temp].size()==0){
            ret.push_back(temp);
            s.pop();   
        }
        else{
            s.push(index[temp][0]);
            index[temp].erase(index[temp].begin());
        }
    }
	return vector<string>(ret.rbegin(),ret.rend());
}
};