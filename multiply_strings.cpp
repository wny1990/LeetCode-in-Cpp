class Solution {
public:
string add(string num1, string num2)
{
	int n1 = num1.size();
	int n2 = num2.size();
	string result(max(n1,n2),'0');
	int carry = 0;
	for( int i = 0; i < max(n1,n2); i++)
	{
		int s1 = 0,s2 = 0;
		if ( n1-i-1 >= 0)
			s1 = num1[n1-i-1]-'0';
		if ( n2-i-1 >= 0)
			s2 = num2[n2-i-1]-'0';
		result[max(n1,n2)-i-1] = (s1 + s2 + carry)%10 + '0';
		carry = (s1 + s2 + carry)/10 ;
	}
	if (carry)
		result.insert(result.begin(),carry+'0');
	return result;
}
string mul_char(string num1,char num2)
{
	int n = num1.size();
	string result(n,'0');
	int carry = 0;
	if (num2 == '0')
		return "0";
	for( int i = 0; i < n; i++)
	{
		int mul = (num1[n-i-1]-'0') *(num2-'0') + carry;
		result[n-i-1] = mul %10 + '0';
		carry = mul/10;
	}
	if (carry)
		result.insert(result.begin(),carry+'0');
	return result;
}
string multiply(string num1, string num2) 
{
        string result;
	result = "0";
	int n = num1.size(); 
	for ( int i = 0; i < n;i++)
	{
		string s1 = mul_char(num2,num1[n-1-i]);
		if (s1 != "0")
			result = add(result ,s1+string(i,'0'));
	}
	return result;
}
};
