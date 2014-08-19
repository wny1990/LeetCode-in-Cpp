/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
int maxPoints(vector<Point> &points) 
{
	if ( points.size() < 2)
		return points.size();
	int maxp = 0;
	for( int i = 0; i < points.size(); i ++)  
	{
		int lmax = 1;
		int vertical = 1;
		int overlap = 0;
		int a1 = points[i].x;
		int b1 = points[i].y;
		map<double,int> lines;
		for( int j = 0; j < i  ; j ++)
		{
			int a2 = points[j].x;
			int b2 = points[j].y;
			if ( a1 == a2 && b1 == b2)
			{
				overlap++;
				continue;
			}
			if ( a1 == a2 )
				vertical++;
			if (!lines.count((b2-b1)*1.0/(a2-a1)) )
			{
				lines[ (b2-b1)*1.0/(a2-a1)] = 2;
				if (2 > lmax)
					lmax = 2;
			}
			else
			{
				int c = lines[(b2-b1)*1.0/(a2-a1)];
				lines[(b2-b1)*1.0/(a2-a1)]++;
				if (c+1 > lmax)
					lmax = c+1;
			}
		}
		maxp = max(maxp,max(vertical+overlap,lmax+overlap));
	}
	return maxp;
}
};
