class Solution {
public:
int maxArea(vector<int> &height) 
{
	int max_area = 0;
	int n = height.size();
	vector<int> minh(height.size(),0);
 	for( int i = n -1 ; i >= 0; i--)
  	{
		if ( height[i] == 0 ) continue;
		for( int len = 1; i + len  < n; len++)
		{
			minh[i] = min(minh[i],height[i+len]);
			if ( max_area < minh[i]*(len+1))
				max_area = minh[i]*(len +1);
			else if ( minh[i]*( n - i + 1) < max_area)
				break;
		}
	}
	return max_area;
}
};
