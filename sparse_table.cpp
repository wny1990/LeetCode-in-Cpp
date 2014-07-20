#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void init_st(vector<int > &nums, vector<vector<int> > &st)
{
	int n = nums.size();
	int m = (log(nums.size())/log(2)) + 1;
	st = vector<vector<int> >  (n,vector<int>(m,0));
	for ( int size = 0; size < m; size++)
		for ( int i = 0; i + pow(2,size) -1 < n; i++)
		{
			if (size == 0)
				st[i][size] = nums[i];
			else
				st[i][size] = min(st[i][size-1],st[i+pow(2,size-1)][size-1]);

		}		
}
int query_min( vector<vector<int> > &st, int s, int e)
{
	int k = log(e - s + 1)/log(2);
	return min(st[s][k],st[e-pow(2,k)+1][k]);
}
int main()
{
	vector<int> nums;
	vector< vector<int> >  st;
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(1);
	nums.push_back(9);
	nums.push_back(7);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(11);
	nums.push_back(6);
	nums.push_back(18);
	nums.push_back(16);
	nums.push_back(1128);
	nums.push_back(128);
	init_st(nums,st);
	cout << query_min(st,0,3) << endl;
	cout << query_min(st,1,6) << endl;
	cout << query_min(st,3,7) << endl;
	cout << query_min(st,5,9) << endl;
	cout << query_min(st,9,11) << endl;
}
