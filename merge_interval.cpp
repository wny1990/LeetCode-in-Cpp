/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class CompareP {
public:
    bool operator()(const Interval &t1, const Interval &t2)
    {
       if (t1.start > t2.start) return true;
       return false;
    }
};

class Solution {
public:
vector<Interval> merge(vector<Interval> &intervals) 
{
	priority_queue<Interval,vector<Interval>,CompareP> q;	
	vector<Interval> result;
	for ( int i = 0; i < intervals.size(); i++ )
	{
			q.push(intervals[i]);
	}
	while (q.size())
	{
		Interval it = q.top();
		q.pop();
		if (result.empty() || it.start > result.back().end)
			result.push_back(it);
		else
		{
			Interval it1 = result.back();
			result.pop_back();
			result.push_back(Interval(it1.start,max(it.end,it1.end)));
		}
	}
	return result;
}
};
