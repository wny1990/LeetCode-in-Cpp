class Solution {
public:
int trap(int A[], int n) 
{
	int lmax[n];
	int rmax[n];
	int water = 0;
	int max = 0;
	for ( int i = 0; i < n; i++)
	{
		lmax[i] = 0; rmax[i] = 0;
	}
	for ( int i = 0; i < n; i++)
	{
		lmax[i] = max;
		if (A[i] > max) 
			max = A[i];
	}
	max = 0;
	for ( int i = n-1; i >= 0; i--)
	{
		rmax[i] = max;
		if (A[i] > max) 
			max = A[i];
	}
	

	for ( int i = 0; i < n; i++)
		if( min(rmax[i],lmax[i])- A[i] >0 )
			water+= min(rmax[i],lmax[i])-A[i];
	return water;
}
};
