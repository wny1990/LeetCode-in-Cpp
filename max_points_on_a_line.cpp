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
	unordered_map< pair<ratio,ratio>,int > lines;
	for( int i = 0; i < points.size(); i ++)  
		for( int j = 0; j < i  ; j ++)
		{
			points[i].x = a1;
			points[i].y = b1;
			points[j].x = a2;
			points[j].y = b2;
			if (lines.count( {ratio<b1*a2-a1*b2,a2-a1>,ratio<b2-b1,a2-a1>}))  
				lines[{ratio<b1*a2-a1*b2,a2-a1>,ratio<b2-b1,a2-a1>}]++;
			else
				lines.insert( {ratio<b1*a2-a1*b2,a2-a1>,ratio<b2-b1,a2-a1>} );
		}
	return 0;
}
};
