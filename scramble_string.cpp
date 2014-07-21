class Solution {
public:
bool anagram(string s1, string s2)
{
	vector<int> tag1(255,0);
	vector<int> tag2(255,0);
	for( int i = 0; i < s1.size();i++)
		tag1[s1[i]]++;
	for( int i = 0; i < s1.size();i++)
		tag2[s2[i]]++;
	if( tag1 != tag2 )
		return false;
	return true;

}
bool scramble( string s1, string s2)
{
	int n = s1.size();
	if (n == 1)
	{
		if (s1[0] == s2[0])
			return true;
		else
			return false;
	}
	for( int i = 1; i < s1.size();i++)
	{
		string left,right;
		left = s1.substr(0,i);
		right = s1.substr(i,n-i);
		if ( anagram(left,s2.substr(0,i)) && anagram(right,s2.substr(i,n-i)))
		{
			if ( scramble(left,s2.substr(0,i)) && scramble(right,s2.substr(i,n-i)))
			return true;
		}
		
		if ( anagram(left,s2.substr(n-i,i)) && anagram(right,s2.substr(0,n-i)))
		{
			if ( scramble(left,s2.substr(n-i,i)) && scramble(right,s2.substr(0,n-i)))
			return true;
		}
	}
	return false;
}
bool isScramble(string s1, string s2) 
{
	if (!anagram(s1,s2))
		return false; 
	if (!scramble(s1,s2))
		return false;
	return true;
}
};
