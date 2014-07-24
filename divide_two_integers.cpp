#include<iostream>
#include<limits.h>
using namespace std;
//class Solution {
//public:
int divide(int dividend, int divisor) 
{
	int result = 0;
	int k = 0;
	int sign = 0;
	if ( (dividend < 0 && divisor >0) || (dividend >0 && divisor <0) )
		sign = 1;
	unsigned int dd,dr;
	if ( dividend < 0) 
		dd = ~dividend + 1;
	else
		dd = dividend;
	if ( divisor < 0) 
		dr = ~divisor + 1;
	else
		dr = divisor;
	if ( dd == 0 || dd < dr ) 
		return 0;

	if ( dd ==  dr ) 
	{
		if (sign)
			return -1;	
		else
			return 1;
	}
	while ( dd >=  (dr << 1) )
	{
		k++;
		dr = dr << 1;
		if ((dr << 1)>>1 != dr) break;
	}

	for ( int i =k; i >= 0; i--)
	{
		result = result << 1;
		if ( dd >= dr )
		{
			dd -= dr;
			result = result | 1;
		}
		dd = dd << 1;
	}
	if (sign) result = ~result + 1;
  
      return result;
}
//};
int main()
{
	cout << divide(-1010369383, -2147483648) << endl;
	cout << divide(-2147483648, 2) << endl;
	cout << 1010369383/2147483648 << endl;
}
