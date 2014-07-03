class Solution {
public:
int climbStairs(int n) 
{
	int num[n+1];
	num[0] = 1;
	num[1] = 1;
	if (n == 0 || n==1) return 1;
	for(int i =0; i<=n ; i++)
		num[i] = num[i-1] + num[i-2];        
	return num[n];
}
};
