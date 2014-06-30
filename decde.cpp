class Solution {
public:
bool valid( string s )
{
	int sum = 0;
	for ( int i =0; i < s.size(); i++)
	{
		sum = sum *10;
		sum+= (s[i]-'0');
		if (sum == 0)
			return false;
	}
	if (sum >26)
		return false;
	return true;
}


int numDecodings(string s) 
{
	if (s.empty()) return 0;
 	int num[s.size()];
	if (s[0] == '0')
		num[0] = 0;
	else
		num[0] = 1;
	for( int i = 1 ; i < s.size(); i++)    
	{
		int k1=0;k2=0;
		if( valid(s.substr(i-1,2)))
			k1 = 1;
		if ( s[i] != '0' )
			k2 = 1;	
		if ( i==1)
			num[i] = k1 + k2*num[i-1];
		else
			num[i] = k1*num[i-2] + k2*num[i-1];
	}
	return num[s.size()-1];   
}
};
