460. LFU Cache


Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LFUCache cache = new LFUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.get(3);       // returns 3.
cache.put(4, 4);    // evicts key 1.
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4


struct info {
	int value;
	int frequency;
	list<int>::iterator iter;
};

class LFUCache {
public:
	LFUCache(int capacity) :maxsize(capacity) {

	}

	int get(int key) {
        if(maxsize==0)
            return -1;
		if (index.count(key))
		{
			frequency_index[index[key].frequency].erase(index[key].iter);
			if (frequency_index[index[key].frequency].size() == 0)
				frequency_index.erase(index[key].frequency);
			index[key].frequency++;
			frequency_index[index[key].frequency].push_back(key);
			index[key].iter = --(frequency_index[index[key].frequency].end());
			return index[key].value;
		}
		return -1;
	}

	void put(int key, int value) {
        if(maxsize==0)
            return;
		if (index.count(key)) {
			get(key);
		}
		else//如果以前不存在
		{
			if (currentsize < maxsize)//还有容量
			{
				index[key].value = value;
				index[key].frequency = 1;
				frequency_index[1].push_back(key);
				index[key].iter = --(frequency_index[1].end());
				currentsize++;
			}
			else//没有容量
			{
                index.erase((*frequency_index.begin()).second.front());
				(*frequency_index.begin()).second.pop_front();
				if (frequency_index[(*frequency_index.begin()).first].size() == 0)
					frequency_index.erase(frequency_index.begin());
				index[key].value = value;
				index[key].frequency = 1;
				frequency_index[1].push_back(value);
				index[key].iter = --(frequency_index[1].end());
			}
		}

	}
	
private:
	int maxsize = 0,currentsize = 0;

	unordered_map<int, info>index;//index.first = val;index.second = frequency;
	map<int,list<int>> frequency_index;
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 
 
 
 class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (m.count(key) == 0) return -1;
        freq[m[key].second].erase(iter[key]);
        ++m[key].second;
        freq[m[key].second].push_back(key);
        iter[key] = --freq[m[key].second].end();
        if (freq[minFreq].size() == 0) ++minFreq;
        return m[key].first;
    }
    
    void put(int key, int value) {
        if (cap <= 0) return;
        if (get(key) != -1) {
            m[key].first = value;
            return;
        }
        if (m.size() >= cap) {
            m.erase(freq[minFreq].front());
            iter.erase(freq[minFreq].front());
            freq[minFreq].pop_front();
        }
        m[key] = {value, 1};
        freq[1].push_back(key);
        iter[key] = --freq[1].end();
        minFreq = 1;
    }

private:
    int cap, minFreq;
    unordered_map<int, pair<int, int>> m;
    unordered_map<int, list<int>> freq;
    unordered_map<int, list<int>::iterator> iter;
};