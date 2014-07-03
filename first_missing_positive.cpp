class Solution {
public:
int firstMissingPositive(int A[], int n) 
{
	int i;
	for( i = 0; i < n; i++)
	{
		if (A[i] == i+1 || A[i] < 1 || A[i] > n )       
			continue;
		int j = A[i];
		A[i] = -1;
		while( j > 0 && j <= n && A[j-1] != j)
		{
			int temp = A[j - 1];
			A[j - 1] = j;
			j = temp;
		}
	}

	for ( i = 0; i < n; i++)
		if (A[i] != i +1)
			break;
	return i;
}
};
