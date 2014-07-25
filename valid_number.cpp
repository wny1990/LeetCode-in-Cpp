#include<iostream>
#include<string>
using namespace std;
//class Solution {
//public:
inline bool is_dig( char c)
{
	if ( c >= '0' && c <= '9')
		return true;
	return false;

}
bool isNumber(const char *s) 
{
	while( *s == ' ')
		s++;
	string str(s); 
	while(str.size() && str.back() == ' ')
		str.pop_back(); 
	if (str.empty() )      
		return false;
	enum STATUS
	{
		UNDEFINED,
		INT_PART,
		DEC_PART,
		EXP_PART,
	};
	enum STATUS status;
	status = UNDEFINED;
	bool sign = false;
	for( int i = 0; i < str.size(); i++)
	{
		
		if (status == UNDEFINED)
		{
			
			if (str[i] == '-' || str[i] == '+')
			{
				if (sign)
					return false;
				sign = true;
				continue;
			}
			else if (is_dig(str[i]))
			{
				status = INT_PART;
				continue;
			}
			else if (str[i] == '.')
			{
				if (!is_dig(str[i+1]))
					return false;
				status = DEC_PART;
				continue;
			}
			else
				return false;
	
		}
		else if (status == INT_PART)
		{
			if ( is_dig(str[i]))
				continue;
			else if (str[i] == 'e')
			{
				if (str[i+1] == '-' || str[i+1] == '+' )
					i++;
				else if (!is_dig(str[i+1]))
					return false;
				status = EXP_PART;
				continue;
			}
			else if (str[i] == '.')
			{
				if (str[i+1] == '-' || str[i+1] == '+')
				{
					i++;
					if (!is_dig(str[i+1]))
						return false;
				}
				status = DEC_PART;
				continue;
			}
			else
				return false;
		}
		else if (status == DEC_PART)
		{
			if ( is_dig(str[i]))
				continue;
			else if (str[i] == 'e')
			{
				if (str[i+1] == '-' || str[i+1] == '+')
					i++;
				if (!is_dig(str[i+1]))
					return false;
				status = EXP_PART;
				continue;
			}
			else
				return false;
		}
		else if (status == EXP_PART)
		{
			if ( is_dig(str[i]))
				continue;
			else
				return false;
		}
	
	}
	if (!is_dig(str.back()) && str.back() != '.' )
		return false;
	return true;
}
//};
int main()
{
	cout << isNumber("-321.1e2") << endl;
	cout << isNumber("321e-2") << endl;
	cout << isNumber("e1") << endl;
	cout << isNumber(".2") << endl;
	cout << isNumber("2.") << endl;
	cout << isNumber("2.e3") << endl;
	cout << isNumber("2.e") << endl;
}
