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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.empty()) return vector<Interval>{};
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        res.push_back(intervals[0]);
        //std::cout << 1 << std::endl;
        intervals.erase(intervals.begin());
        for(auto c : intervals){
            if(res.back().end < c.start) res.push_back(c);
            else{
                res.back().end = max(res.back().end, c.end);
            }
        }
        return res;
    }
};