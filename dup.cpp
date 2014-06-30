class Solution {
public:
int removeDuplicates(int A[],int n)
{
	int dup = 0;
	for(int i = 0; i < n; i++)
		if (i==0 || A[i]!=A[i-1])
			A[i-dup] = A[i];
		else
			dup++;
	return (n-dup);       
}
};
