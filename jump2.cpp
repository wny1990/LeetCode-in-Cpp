class Solution {
public:
int jump(int A[], int n) 
{
	int reach = 0;
	int step[n] ;
	step[0] = 0;	
	for ( int j = 0; j < n;j++)
	{	
		if (reach >= n-1) return step[n-1];
		if (A[j] + j> reach) 
		{
			for ( int i=reach +1; i<=A[j]+j; i++)
				step[i] = step[j] + 1;
			reach = A[j] + j;
		}
	}
	return 0;
}
};
