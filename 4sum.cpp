class Solution {
public:

vector<vector<int> > fourSum(vector<int> &numbers, int target) 
{

	vector< vector<int> > result;
	vector<int>::iterator hh,ii,jj,kk;
	int last1,last2,last3;
	last1 = INT_MIN;
	last2 = INT_MIN;
	last3 = INT_MIN;
        sort(numbers.begin(),numbers.end());
	if ( numbers.size() < 4 ) return result;
	for(ii = numbers.begin(); ii != numbers.end() -3; ii++)
	{ 
		if (*ii > target) break;
		if(ii!=numbers.begin() && *ii == *(ii-1) )
   		     continue;
		for(hh = numbers.begin() + 1; hh != numbers.end() -2; hh++)
		{
			if(hh!=numbers.begin()  + 1 && *hh== *(hh-1) )
				continue;
		jj = hh + 1;
		kk = numbers.end() - 1;
		while ( jj <kk)
		{
			if (*ii + *hh + *jj + *kk == target)
			{
				if ( *ii > last1 || (*ii == last1 && *hh > last2) || ( *ii==last1 && *hh==last2 && *jj > last3) )
				{
					vector<int> temp;
					temp.push_back(*ii);
					temp.push_back(*hh);
					temp.push_back(*jj);
					temp.push_back(*kk);
					result.push_back(temp);
					last1 = *ii;
				  	last2 = *hh;
					last3 = *jj;
				}
				jj ++ ;kk--;
			}
			else if (*ii + *hh + *jj + *kk > target)
				kk--;
			else 
				jj++;
		}

	}	  
	}
	return result;
}
};
