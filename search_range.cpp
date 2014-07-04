class Solution {
public:
vector<int> searchRange(int A[], int n, int target) 
{
	if (n == 0)
		return false;
        int left = -1;
        int right = n;
	while (left <= right )
	{
		int pivot = (right + left)/2;
		int value = A[pivot];
		if ( value >= target)
			right = pivot - 1;
		else
			left = pivot + 1;
	}
	return false;
}
};
