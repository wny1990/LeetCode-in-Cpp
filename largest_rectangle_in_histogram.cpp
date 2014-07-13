#include<iostream>
#include<vector>
#include<ctime>

using namespace std;
//class Solution {
//public:
void area(vector<int> &height , int i, int j)
{
	if (i=j)
		return height[i];
	if ( j - i == 1)
		return min(height[i],height[j])*2;
	int s1 = area

}
int largestRectangleArea(vector<int> &height) 
{
	return area(height,0,height,size());

}
/*
int largestRectangleArea(vector<int> &height) 
{
	int max_area = 0;
	int n = height.size();
	vector<int> minh(height.size(),0);
 	for( int i = 0 ; i < n; i++)
  	{
		minh[i] = height[i];
		if (i && height[i] < height[i-1])
			continue;
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
*/


//};
int main(){

	vector<int> height;
	for(int i = 0; i < 9000; i++)
		height.push_back(i);
	time_t t1 = clock();
	cout << largestRectangleArea(height) << endl;
	time_t t2 = clock();
	cout << "time: " << t2 - t1 << endl;
	return 0;
}
