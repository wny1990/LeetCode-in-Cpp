class Solution {
public:
int maxProfit(vector<int> &prices) 
{
	int n = prices.size();
	if ( n == 0 )
		return 0;
	vector<int> before(n,0);      
	vector<int> after(n,0);
	int i;
	int profit = 0;
	int min = INT_MAX;
	for ( i = 0; i < n; i++)
	{
		if (prices[i] - min > profit)
			profit = prices[i] - min;
		before[i] = profit;
		if (prices[i] < min )
			min = prices[i];
	}  
	profit = 0;
	int max = 0;
	for ( i = n - 1; i >= 0; i--)
	{
		if (max - prices[i]  > profit)
			profit = max - prices[i];
		after[i] = profit;
		if (prices[i] > max )
			max = prices[i];
	} 
	int max_profit = 0;
	for ( i = n - 1; i >= 0; i--)
		if (before[i] + after[i] > max_profit)
			max_profit =  before[i] + after[i];
	return max_profit;
}
};
