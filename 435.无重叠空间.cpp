435.无重叠空间

应用贪心算法，按结束时间进行排序

给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]

输出: 1

解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:

输入: [ [1,2], [1,2], [1,2] ]

输出: 2

解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3:

输入: [ [1,2], [2,3] ]

输出: 0

解释: 你不需要移除任何区间，因为它们已经是无重叠的了。


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    
    static bool comp(Interval a,Interval b){
        if(a.end<b.end)
            return true;
        else if(a.end==b.end){
            if(a.start>=b.start)
                return true;
        }
        return false;
    }
    
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.size()==0)
            return 0;
        sort(intervals.begin(),intervals.end(),comp);
        int end = intervals.back().start;
        int cnt = 1;
        Interval temp = intervals[0];
        for(auto val:intervals){
            if(temp.end==val.end)
                continue;
            else{
                if(val.start>=temp.end){
                    cnt++;
                    temp = val;
                }
            }
        }
        
        return intervals.size()-cnt;
    }
};