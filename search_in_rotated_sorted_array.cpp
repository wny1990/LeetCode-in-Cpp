class Solution {
public:
int search(int A[], int n, int target) 
{
        int left = 0;
        int right = n - 1;
	while (left <= right )
	{
		int pivot;
		int value;
		if (A[right] < A[left])
		{
			pivot = ((right + left + n )/2)%n;
			value = A[pivot];
			if ( value == target)
				return pivot;
			else if ( pivot < left)
			{
				right  = left;
				left  = pivot +  1;
			}
			else if ( pivot > right)
			{
				left = right;
				right = pivot + 1;
			}
		}
		else
		{
			pivot = (right + left)/2;
			value = A[pivot];
			if ( value == target)
				return pivot;
			else if ( value > target)
				right = pivot - 1;
			else
				left = pivot + 1;
		}
	}
	return -1;
}
};
