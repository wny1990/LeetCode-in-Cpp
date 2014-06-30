class Solution {
public:
int sqrt(int x)
{
	int upper = x ;
	int lower = 0;
	if (x == 1) return 1;
	if (x == 0) return 0;
	while ( upper - lower > 1 )
	{
		
		if ( ((upper + lower)/2)  * ( (upper + lower)/2) == x )
			return (upper + lower)/2;
		else if ( ((upper + lower)/2)  * ( (upper + lower)/2) > x )
			upper = (upper + lower)/2;
		else
			lower =( upper + lower)/2;
	}
	if (upper*upper == x) return upper;
	return lower;
}
};
