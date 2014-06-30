class Solution {
public:
int removeDuplicates(int A[],int n)
{
	int dup = 0;
	int sumdup = 0;
	bool last_dup = false;
	if (n ==1) return 1;
	for(int i = 1; i < n; i++)
		if ( A[i] != A[i-1])
		{
			if(last_dup)
			{
				 A[i-sumdup+dup-1] = A[i-1];
				 dup++;
			}
			last_dup = false;
			A[i-sumdup+dup] = A[i];
		}
		else
		{
			last_dup = true;			
			sumdup++;
		}
	if ( last_dup) dup++;
	return (n-sumdup+dup);       
}
};
