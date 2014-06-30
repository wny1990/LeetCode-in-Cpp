class Solution {
public:
vector<int> searchRange(int A[], int n, int target) 
{
	vector<int> result;
	if (n == 0)
		return false;
        int left = 0;
        int right = n - 1;
	
	while (left < right )
	{
		int pivot = (right + left)/2;
		int value = A[pivot];
		if ( value >= target)
			right = pivot - 1;
		else
			left = pivot + 1;
	}

	if ( 

        left = 0;
        right = n - 1;
	while (left <= right )
	{
		int pivot = (right + left)/2;
		int value = A[pivot];
		if ( value <= target)
			right = pivot - 1;
		else
			left = pivot + 1;
	}


	return false;
}
