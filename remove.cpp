class Solution {
public:
int removeElement(int A[], int n, int elem) 
{
	int removed = 0;
	for(int i = 0; i < n; i++)
		if (A[i]!=elem)
			A[i-removed] = A[i];
		else
			removed++;
	return (n-removed);       
}
};
