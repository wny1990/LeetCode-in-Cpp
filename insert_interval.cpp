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
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
{
	int n = intervals.size();
	if (n == 0 || intervals.back().end < newInterval.start)
	{
		intervals.push_back(newInterval);
		return intervals;
	}      
	int i;
	for( i = 0; i < n && intervals[i].end  
}
};
