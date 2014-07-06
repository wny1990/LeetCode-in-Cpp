class Solution {
public:
void nextPermutation(vector<int> &num) 
{
	if (num.size() < 2 )
		return;
	int index = -1;
	for(int i = num.size() - 2; i >= 0; i--)
	{
		if (num[i] < num[i+1])
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{
		sort(num.begin(),num.end());
		return;
	}
	int min = INT_MAX;
	int index_min;
	for( int i = index + 1; i < num.size(); i++)
	{
		if ( num[i] > num[index] && num[i] < min)
		{
			min = num[i];
			index_min = i;
		}
	}
	swap(num[index],num[index_min]);
	sort(num.begin()+index+1,num.end());
	return;
}
};
