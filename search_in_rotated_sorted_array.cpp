class Solution {
public:
int search(int A[], int n, int target) 
{
        int left = 0;
        int right = n - 1;
	while ( right - left > 1)
	{
		int pivot;
		int value;
		pivot = (right + left)/2;
		value = A[pivot];
		if (value < A[right])
			right = pivot;
		else if (value > A[left])
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
		{
			if (pivot >= n)
				return (pivot - n);
			else
				return pivot;
		}
		else if ( value > target)
			right = pivot - 1;
		else
			left = pivot + 1;
	}
	return -1;
}
};
