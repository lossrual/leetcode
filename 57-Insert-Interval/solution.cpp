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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        //if(intervals.size() == 0) return vector<Interval>(newInterval.start, newInterval.end);
        int i = 0;
        while(i < intervals.size() && intervals[i].end < newInterval.start){
            res.push_back(intervals[i]);
            i++;
        }
        while(i < intervals.size() && intervals[i].start <= newInterval.end){
            newInterval.start = min(intervals[i].start, newInterval.start);
            newInterval.end = max(intervals[i].end, newInterval.end);
            i++;
        }
        res.push_back(newInterval);
        while(i < intervals.size()){
            res.push_back(intervals[i++]);
        }
        return res;
    }
};