class Solution {
public:
int threeSumClosest(vector<int> &num, int target)
{

	int result;
	int ii,jj;
	int diff = INT_MAX;
        sort(num.begin(),num.end());
	for(ii = 0; ii != num.size() - 2; ii++)
		for(jj = ii + 1; jj != num.size() - 1; jj++)
			{
				int left = jj + 1;
				int right = num.size() - 1;
				while (  right - left > 1)
				{
					int pivot = (left + right)/2;
					int value = num[pivot];
					if (value + num[ii] + num[jj] <= target)
						left = pivot;
					else if (value + num[ii] + num[jj] > target)
						right = pivot;
				}
				if (abs(num[left] + num[ii] + num[jj] - target) < diff)
				{
					diff = abs(num[left] + num[ii] + num[jj] - target);
					result = num[left] + num[ii] + num[jj];
				}
				if (abs(num[right] + num[ii] + num[jj] - target) < diff)
				{
					diff = abs(num[right] + num[ii] + num[jj] - target);
					result = num[right] + num[ii] + num[jj];
				}
			}	
	return result;
}
};
