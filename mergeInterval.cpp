/**
 * Merge Intervals
 * Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
 * 
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
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = intervals.size();
        vector<Interval> v;
        if (n < 1) return v;
        struct {
            bool operator()(Interval a, Interval b)
            {   
                return a.start < b.start;
            }   
        } customLess;
        sort(intervals.begin(), intervals.end(), customLess);
        Interval prev = intervals[0];
        v.push_back(prev);
        for (int i = 1; i < n; i++) {
            if (v[v.size() - 1].end >= intervals[i].start) {
                if (v[v.size() - 1].end < intervals[i].end)
                    v[v.size() - 1].end = intervals[i].end;
            } else {
                v.push_back(intervals[i]);
            }
        }
        return v;
    }
};