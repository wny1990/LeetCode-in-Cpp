class Solution {
public:
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) 
{
	int min = INT_MAX;
	int index = 0;        
	int sum = 0;        
	for(int i = 0; i < gas.size(); i++)
	{
		sum += gas[i] - cost[i];
		if( sum < min)
		{
			min = sum;
			index = (i+1) % gas.size();
		}
	}
	if (sum<0) return -1;
	return index;
}
};
