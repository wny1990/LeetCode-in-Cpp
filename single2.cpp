class Solution {
public:
int singleNumber(int A[], int n) 
{
	int sum[32] = {0};
	for(int i=0; i<n;i++)
	{
		for ( int b = 0; b < 32; b++)
			sum[b]+= ((A[i] >> b)%2);
	}
	int result = 0;
	for ( int b = 0; b < 32; b++)
		if (sum[b]%2 != 1)
			result = result || (1 << b);
	return result;
}
};
