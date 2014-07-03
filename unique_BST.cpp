class Solution {
public:
int numTrees(int n) 
{
	int num[n+1];

        num[0] = 1;
        num[1] = 1;
	if ( n == 0 || n == 1) return 1;

	for(int k=2; k<=n;k++)
	{
		int sum = 0;
		for(int i=0; i<k;i++)
			sum += num[i]*num[k-1-i];
		num[k] = sum;
	}
	return num[n];
}
};
