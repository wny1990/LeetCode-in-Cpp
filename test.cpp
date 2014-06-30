#include "iostream"
#include <vector>
#include <ctime>
using namespace std;
//class Solution {
//public:
bool palindrome( string s)
{
	int i = 0;
	int j = s.size() - 1;
	while ( i < j)
	{
		if ( s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

int minCut(string s)
{
	if (s.size() == 0 || s.size() == 1) return 0;
	int n = s.size();

        vector<vector<bool> > isPal(n,vector<bool>(n,false));

	int min_cut[n];

	for ( int i = 0; i < n; i++)
		min_cut[i] = i;


	for ( int i = 0; i < n; i++ )
		for ( int j = i; j >= 0; j-- )
//		for ( int j = 0; j <= i; j++ )
		{
			if ( i - j == 1 )
				isPal[j][i] = palindrome(s.substr(j,2));

			else if ( i == j || (  (s[i] == s[j]) && isPal[j+1][i-1])  )

				isPal[j][i] = true;
			else
				isPal[j][i] = false;
			
			if ( isPal[j][i] == true && j ==0)
			{
				min_cut[i] = 0;
				break;
			}
			if ( isPal[j][i]== true && min_cut[j-1] + 1 < min_cut[i])
			{	
				min_cut[i] = min_cut[j-1] + 1;
			}
		}


	return min_cut[n-1];
}
/*
int minCut(string s)
{
	if (s.size() == 0 || s.size() == 1) return 0;

       	vector<vector<bool> > isPal;
	int n = s.size();
// initialize the bool matrix
	for ( int i = 0; i < n; i++ )
	{
		vector<bool> row(s.size(),false);
		isPal.push_back(row);
	}
// calculate the bool matrix
	time_t t1 = clock();
	for ( int len = 1; len <= n; len++ )
		for ( int i = 0; i + len - 1 < n; i++ )
		{
			if ( len == 1)
				isPal.at(i).at(i) = true;
			else if ( len == 2 )
				isPal.at(i).at(i+len-1) = palindrome(s.substr(i,len));
			else if ( s[i] == s[i+len-1])
				isPal.at(i).at(i+len-1) = isPal.at(i+1).at(i+len-2);
			else
				isPal.at(i).at(i+len-1) = false;
		}

	time_t t2 = clock();
	cout <<"bool matrix:" <<t2- t1 << endl;
	int min_cut[n];

	for ( int i = 0; i < n; i++)
		min_cut[i] = i;

	for ( int i = 1; i < n; i++)
	{
		if ( isPal.at(0).at(i))
		{
			min_cut[i] = 0;
			continue;
		}
		for ( int j = 0; j < i; j++)
		{
			if ( isPal.at(j + 1).at(i) && min_cut[j] + 1 < min_cut[i])
			{
				min_cut[i] = min_cut[j] + 1;
				if (min_cut[i] == 1) break;
			}
		}

	}
	return min_cut[n-1];
}
*/
//};

  int min_Cut(string s) {
            if(s.empty()) return 0;
            int n = s.size();
            vector<vector<bool> > pal(n,vector<bool>(n,false));
            vector<int> d(n);
            for(int i=n-1;i>=0;i--)
            {
                d[i]=n-i-1;
                for(int j=i;j<n;j++)
                {
                    if(s[i]==s[j] && (j-i<2 || pal[i+1][j-1]))
                    {
                       pal[i][j]=true;
                       if(j==n-1)
                           d[i]=0;
                       else if(d[j+1]+1<d[i])
                           d[i]=d[j+1]+1;
                    }
                }
            }
            return d[0];
        }

int main()
{
	time_t t1 = clock();
	cout << minCut("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl;

	time_t t2 = clock();
	cout << t2 - t1 << endl;
}
