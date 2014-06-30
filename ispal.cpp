class Solution {
public:
    bool isPalindrome(string s)
    {
   	if (s.size() < 2) return true;
	int i = 0;
	int j = s.size() -1;
	while ( j > i)
	{
		while ( !( (s[i] >= 'a' && s[i] <= 'z') ||  (s[i] >= 'A' && s[i] <= 'Z') || (s[i]>='0' && s[i] <='9'))  && s[i] != '\0')
			i ++;
		while ( !( (s[j] >= 'a' && s[j] <= 'z') ||  (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >='0' && s[j] <='9' )) && j >0 )
			j --;
		if ( j <= i) return true;
		if ( (s[i]- s[j]) == 0 ||  (s[i]- s[j]) == -32 || (s[i]- s[j]) == 32 )
		{
			i++;j--;
		}
		else
			return false;
	}    
	return true;
    }
};
