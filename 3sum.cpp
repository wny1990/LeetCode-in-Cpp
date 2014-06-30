#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int> &numbers) 
{

	vector< vector<int> > result;
	vector<int>::iterator ii,jj,kk;
	int last1,last2;
	last1 = INT_MIN;
	last2 = INT_MIN;
        sort(numbers.begin(),numbers.end());
	if ( numbers.size() < 3 ) return result;
	for(ii = numbers.begin(); ii != numbers.end() -2; ii++)
	{
		jj = ii + 1;
		kk = numbers.end() - 1;
		while ( jj != kk)
		{
			if (*ii + *jj + *kk == 0)
			{
				if ( *ii > last1 || *jj > last2)
				{
				vector<int> temp;
				temp.push_back(*ii);
				temp.push_back(*jj);
				temp.push_back(-(*ii + *jj));
				result.push_back(temp);
				last1 = *ii;
			        last2 = *jj;
				}
				jj ++ ;
			}
			else if (*ii + *jj + *kk > 0)
				kk--;
			else 
			//if (*ii + *jj + *kk < 0)
				jj++;
		}
	}
/*		for(jj = ii + 1; jj != numbers.end() - 1 ; jj++)
			if ( *ii > last1 || *jj > last2)
				if(( jj + 1 != numbers.end()) && binary_search(jj + 1,numbers.end(),-( *ii + *jj )))
				{
					vector<int> temp;
					temp.push_back(*ii);
					temp.push_back(*jj);
					temp.push_back(-(*ii + *jj));
					result.push_back(temp);
					last1 = *ii;
			                last2 = *jj;
				}	
*/
	return result;
}

int main()
{
	vector<int> numbers;
	vector<vector<int> > three;
	numbers.push_back(-1);
	numbers.push_back(0);
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(-1);
	numbers.push_back(-1);
	numbers.push_back(-1);
	numbers.push_back(-1);
	numbers.push_back(-4);
	numbers.push_back(4);
	numbers.push_back(-3);
	numbers.push_back(-8);
	numbers.push_back(-6);
	numbers.push_back(3);
	three = threeSum(numbers);
	vector<vector<int> >::iterator ii;
	vector<int>::iterator jj;
	for(ii = three.begin(); ii!= three.end(); ii++)
	{
		for(jj = (*ii).begin(); jj!= (*ii).end(); jj++)
		cout << *jj << " ";
		cout << endl;
	}
	return 0;
}
