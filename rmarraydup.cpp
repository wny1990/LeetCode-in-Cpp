int removeDuplicates(int A[], int n) 
{
	int B[n];
	int dup  = 0;
	if (n == 1) return 1;
	B[0] = 0;
	for(int i = 1; i < n; i++ )
		if (A[i] == A[i-1] ) 	
		{
			index[i] = index[i-1];
			dup ++;
		}
		else
			index[i] = index[i-1] + 1;

	for(int i = 0; i < n - dup; i++ )
		
}
