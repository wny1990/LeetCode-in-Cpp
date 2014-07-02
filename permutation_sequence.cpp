class Solution {
public:
string getPermutation(int n, int k) 
{
	vector<int> fac(n + 1,0);
	vector<char> alpha;
	string result;
	for(int i = 1 ; i <= n; i++)       
		alpha.push_back(i+'0');
	
	int i;
	int sum = 1;
	for( i = 1; i <= n; i++)
	{
		sum*=i;
		fac[i] = sum;
	}
	fac[0] = 1;
	for ( int j = n; j >= 2; j--)
	{
		int num;

		if ( k % fac[j - 1] != 0 )
		{
			num = k/fac[j - 1];
			k = k % fac[j - 1];
		}
		else
		{
			num = k/fac[j - 1] - 1;
			k =  fac[j - 1];
		}			
		result.push_back(alpha[num]);
		alpha.erase(alpha.begin() + num);
		sort(alpha.begin(),alpha.end());
	}
	result.push_back(alpha[0]);
	return result;
}
};
