class Solution {
public:
int maxArea(vector<int> &height) 
{
	int max_area = 0;
	int heighest = 0;
	int n = height.size();
 	for( int i = 0 ; i < n - 1; i++)
  	{
		if ( height[i] <= heighest ) 
			continue;
		heighest = height[i];
		int h1 = 0;
		for( int len = n -i - 1 ; len  >=  1; len--)
		{
			if (height[i+len] > h1)
				h1 = height[i+len];
		        max_area =  max(min(height[i],height[i+len])*len,max_area);
			if (h1 >= height[i] )
				break;
		}
	}
	return max_area;
}
};
