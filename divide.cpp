class Solution {
public:
int divide(int dividend, int divisor) 
{
	int result;
	int k = 0;
	int sign = 0;
	if (dividend == 0) return 0;
	if ( (dividend < 0 && divisor >0) || (dividend >0 && divisor <0) )
		sign = 1;
	if ( dividend < 0) dividend = - dividend;
	if ( divisor < 0) divisor = - divisor;
	while ( dividend > (divisor << 1) )
	{
		k++;
		divisor = divisor << 1;
		if ((divisor << 1)>>1 != divisor) break;
	}
	
	for ( int i =k; i >= 0; i--)
	{
		result = result << 1;
		if ( dividend >= divisor)
		{
			dividend -= divisor;
			result = result | 1;
		}
		dividend = dividend << 1;
	}
	if (sign) result = -result;
        return result;
}
};
