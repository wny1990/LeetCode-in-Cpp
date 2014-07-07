class Solution {
public:

vector<vector<int> > fourSum(vector<int> &numbers, int target) 
{

	vector< vector<int> > result;
	int hh,ii,jj,kk;
	int last1,last2,last3;
	last1 = INT_MIN;
	last2 = INT_MIN;
	last3 = INT_MIN;
        sort(numbers.begin(),numbers.end());
	if ( numbers.size() < 4 ) return result;
	for(ii = 0 ; ii != numbers.size() -3; ii++)
	{ 
		if (numbers[ii] > target && target >= 0) break;
		if( ii != 0 && numbers[ii] == numbers[ii-1] )
   		     continue;
		for(hh = ii + 1; hh != numbers.size() -2; hh++)
		{
			if(hh != ii + 1 && numbers[hh]== numbers[hh-1] )
				continue;
		jj = hh + 1;
		kk = numbers.size() - 1;
		while ( jj <kk)
		{
			if (numbers[ii] + numbers[hh] + numbers[jj] + numbers[kk] == target)
			{
				if ( numbers[ii] > last1 || (numbers[ii] == last1 && numbers[hh] > last2) || ( numbers[ii]==last1 && numbers[hh]==last2 && numbers[jj] > last3) )
				{
					vector<int> temp;
					temp.push_back(numbers[ii]);
					temp.push_back(numbers[hh]);
					temp.push_back(numbers[jj]);
					temp.push_back(numbers[kk]);
					result.push_back(temp);
					last1 = numbers[ii];
				  	last2 = numbers[hh];
					last3 = numbers[jj];
				}
				jj ++ ;kk--;
			}
			else if (numbers[ii] + numbers[hh] + numbers[jj] + numbers[kk] > target)
				kk--;
			else 
				jj++;
		}

	}	  
	}
	return result;
}
};
