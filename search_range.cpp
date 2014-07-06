class Solution {
public:
vector<int> searchRange(int A[], int n, int target) 
{
	vector<int> result;
	if (n == 0)
		return result;
        int left = -1;
        int right = n;
	int start(-1),end(-1);
	while (left < right )
	{
		int pivot = (right + left)/2;
		int value = A[pivot];
		if ( value >= target)
			right = pivot - 1;
		else
			left = pivot + 1;
	}
	if (right && A[right] == target )
		start = right;
	else if (A[right + 1] == target )
		start = right + 1;

	left = -1;
	right = n;

	while (left < right )
	{
		int pivot = (right + left)/2;
		int value = A[pivot];
		if ( value <= target)
			left = pivot + 1;
		else
			right = pivot - 1;
	}

	if (right < n && A[right] == target )
		end = right;
	else if (A[right - 1] == target )
		end = right - 1;
	if ( start == -1 || end == -1)
	{
		result.push_back(-1);
		result.push_back(-1);
		return result;
	}
	result.push_back(start);
	result.push_back(end);
	return result;
}
};
