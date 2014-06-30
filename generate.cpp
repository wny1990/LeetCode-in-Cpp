class Solution {
public:
void gene( string s, int left, int right, int n)
{
	string s1,s2;
	s1 = s;
	s2 = s;

	if( left < n)
	{
		s1.push_back('(');
		gene(s1,left + 1, right, n);
	}

	if( right < n && right < left)
	{
		s2.push_back(')');
		gene(s2,left, right + 1, n);
	}

	if (left == n && right == n )
		result.push_back(s);

	return;
}
vector<string> generateParenthesis(int n)
{
        if(n == 0)
		return result;
	string s;
	gene(s,0,0,n);
	return result;
}
private:
	vector<string> result;
};
