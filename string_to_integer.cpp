class Solution {
public:
int atoi(const char *str) 
{
	int sign = 1;
	int index = 0;
	while(str[index] == ' ')
		index++;
	if(str[index] == '-')
		sign = -1;
	if( str[index] == '+'|| str[index] == '-')
		index++;
	if (str[index] < '0' || str[index] > '9')
		return 0;
	int sum = 0;
	for ( int  i = index; str[i]!='\0' ; i ++)
	{
		int sum0 = sum;
		bool overflow = false;
		if (str[i] >= '0' && str[i] <= '9')
		{
			if ((sum << 1) > 0)
				overflow = true;
			if ((sum << 2) > 0)
				overflow = true;
			if ((sum << 3) > 0)
				overflow = true;
				
			sum = (sum << 1) + (sum << 3);
			
			if ( sum > sum0 )
				overflow = true;
			
			sum -= str[i] - '0';
			
			if ( sum > sum0 )
				overflow = true;
			if ( overflow)
			{
				if (sign == 1)
					return INT_MAX;
				else
					return INT_MIN;
			}

		}
		else
			break;
	}

	if (sign == 1 )
	{
		if( sum == INT_MIN)
			return INT_MAX;
		return -sum;
	}
	return sum;
}
};
