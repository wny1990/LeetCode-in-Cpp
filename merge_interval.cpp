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
vector<Interval> merge(vector<Interval> &intervals) 
{
	deque<Interval> result;
	vector<Interval> rt;
	if ( intervals.size() == 0) 
		return rt;
	result.push_back(intervals.at(0));
	for( auto i = intervals.begin() + 1; i != intervals.end(); i++)
 	{
		auto j = result.begin();
		while ( j != result.end() && j->end < i->start  )
			j++;
		if ( j == result.end() )
			result.push_back(*i);
		else
		{
			int s = INT_MAX;
			int e = INT_MIN;
			while(j != result.end() && j->end <= i->end )
			{
				if (j->start < s)
					s = j->start;
				if (j->end > e)
					e = j->end;
				j = result.erase(j);
			}
			result.insert(j,Interval(s,e));
		}
	}      
	for ( auto i = result.begin(); i != result.end(); i++)
		rt.push_back(*i);
	return rt;
}
};
