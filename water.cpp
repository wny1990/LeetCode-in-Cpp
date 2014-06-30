class Solution {
public:
    int maxArea(vector<int> &height) {
	int area[height.size()];
	area[0] = 0;
	for(int i=1; i <height.size();i++)
	{
		if( height[i] >= height[i-1])
			area[i] = area[i-1] + height[i];
		else
	}
    }
};
