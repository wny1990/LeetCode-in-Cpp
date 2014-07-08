class Solution {
public:
int romanToInt(string s) 
{
	int i = 0;
	int sum = 0;
	int n = s.size();

	while( i < n && s[i] == 'M')
	{
		i++;
		sum+=1000;	
	}    
	while( i < n && s[i] == 'C')
	{
		i++;
		sum+=100;	
	}   
	if ( s[i] == 'D' )
	{
		sum -= 2 * (sum%1000) ;
		sum+= 500;
		i++;
	}
	else if ( s[i] == 'M' )
	{
		sum -= 2 * (sum%1000);
		sum+= 1000;
		i++;
	}

	while( i < n && s[i] == 'C')
	{
		i++;
		sum+=100;	
	}   

	while( i < n && s[i] == 'X')
	{
		i++;
		sum+=10;	
	}   
	if ( s[i] == 'L' )
	{
		sum -= 2* (sum%100 );
		sum+= 50;
		i++;
	}

	else if ( s[i] == 'C' )
	{
		sum -= 2* (sum%100) ;
		sum+= 100;
		i++;
	}

	while( i < n && s[i] == 'X')
	{
		i++;
		sum+=10;	
	}   

	while( i < n && s[i] == 'I')
	{
		i++;
		sum+=1;	
	}   
	if ( s[i] == 'V' )
	{
		sum -= 2* (sum%10 );
		sum+= 5;
		i++;
	}
	else if ( s[i] == 'X' )
	{
		sum -= 2*( sum%10);
		sum+= 10;
		i++;
	}

	while( i < n && s[i] == 'I')
	{
		i++;
		sum+=1;	
	}   
	return sum;

}
};
