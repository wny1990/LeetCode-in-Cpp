class Solution {
public:
bool search(int A[], int n, int target) 
{
        int left = 0;
        int right = n - 1;
	if ( A[n-1] == A[0])
	{
		for ( int i = 0; i < n; i++ )
			if (A[i] == target)
				return true;
		return false;
	}
	while ( right - left > 1)
	{
		int pivot;
		int value;
		pivot = (right + left)/2;
		value = A[pivot];
		if (value <= A[right])
			right = pivot;
		if (value >= A[left])
			left = pivot;
	}
	int  offset = left;
	if ( A[n-1] > A[0])
		offset = -1;
	left = offset + 1;
	right = n + offset;
	while (left  <= right )
	{
		int pivot;
		int value;
		pivot = (right + left)/2;
		if (pivot >= n)
			value = A[pivot - n];
		else
			value = A[pivot];
		if ( value == target)
			return true;
		else if ( value > target)
			right = pivot - 1;
		else
			left = pivot + 1;
	}
	return false;
}
};
