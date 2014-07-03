class Solution {
public:
bool canJump(int A[], int n) 
{
	int reach = 0;
	for ( int j=0; j<n;j++)
	{	
		if (j>reach) return false;
		if (A[j] + j> reach) 
			reach = A[j] + j;
		if (reach >= n-1) return true;
	}
	return false;
}
};
