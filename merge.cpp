void merge(int A[], int m, int B[], int n)
{
	
	int ia  = m - 1;
	int ib  = n - 1;
        if (m == 0)
	    for (int i=n-1; i>=0;i--) A[i] = B[i];
	 if (n == 0)
	   return;
	for(int i = m + n - 1 ; i >= 0; i--)
	{
		if ( ib<0 || ia >= 0 && A[ia] >= A[ib] )
		{
			A[i] = A[ia];
			ia--;
		}
		else
		{
			A[i] = B[ib];
			ib--;
		}
	}
	return;
}       
   
