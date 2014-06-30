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
	vector<Interval> result;
	for( int i = 0; i < intervals.size(); i++)
 	{
		for( int j = 0; j < result.size(); j++)
			if ( result.at(j).end < intervals.at(i).begin  )
				break;
		if (j == result.size() )
			result.push_back(intervals.at(i));
		else
		{
			while(result.at(j)!=result.end() && result.at(j).begin > intervals.at(i).end )
				
		}
	}      
}
};
