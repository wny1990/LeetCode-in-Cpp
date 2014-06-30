class Solution {
public:
int threeSumClosest(vector<int> &num, int target)
{

	int result;
	vector<int>::iterator ii,jj;
	int last1,last2;
	last1 = INT_MIN;
	last2 = INT_MIN;
        sort(numbers.begin(),numbers.end());
	if ( numbers.size() < 3 ) return result;
	for(ii = numbers.begin(); ii != numbers.end(); ii++)
		for(jj = ii + 1; jj != numbers.end(); jj++)
			if ( *ii > last1 || *jj > last2)
				//if ( find_num(numbers, jj + 1, -( *ii + *jj )) )
				if(( jj + 1 != numbers.end()) && binary_search(jj + 1,numbers.end(),-( *ii + *jj )))
				{
					vector<int> temp;
					last1 = *ii;
			                last2 = *jj;
				}	
	return result;
}
};
