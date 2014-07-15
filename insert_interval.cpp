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
	int begin;
	int end;
	int left = 0;
	int right = n-1;
	vector<Interval> result;
	if (n == 0)
	{
		result.push_back(newInterval);
		return result;
	}
	if ( intervals[n-1].end < newInterval.start )
	{
		intervals.push_back(newInterval);
		return intervals;	
	}

	if ( intervals[0].start > newInterval.end )
	{
		intervals.insert(intervals.begin(),newInterval);
		return intervals;	
	}

	while( right - left > 1)
	{
		int pivot = (left + right)/2;
		int value = intervals[pivot].end;
		if ( value < newInterval.start )
			left = pivot;
		else
			right = pivot;
	}
	if( intervals[left].end >= newInterval.start )
		begin = left;
	else
		begin = right;
	left = 0; right = n - 1;

	while( right - left > 1)
	{
		int pivot = (left + right)/2;
		int value = intervals[pivot].start;
		if ( value > newInterval.end )
			right = pivot;
		else
			left = pivot;
	}
	if(  intervals[right].start <= newInterval.end)
		end = right;
	else
		end = left;
	for (int  i = 0; i < begin; i++)
		result.push_back(intervals[i]);

	int l = min(intervals[begin].start,newInterval.start);
	int r = max(intervals[end].end,newInterval.end);
	result.push_back(Interval(l,r));

	for (int  i = end + 1; i < n; i++)
		result.push_back(intervals[i]);
	return result;
}
};
