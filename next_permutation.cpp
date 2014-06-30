class Solution {
public:
bool rev_order(vector<int> &num, int pos)
{
	for( int i = pos + 1 ; i < num.size(); i ++ )
		if ( num.at(i) < num.at(pos) )
			return false;
	return true;
}

void nextPermutation(vector<int> &num) 
{
 	for(int i = 0; i <  num.size() ; i++)
		if ( rev_order(num,i))
			break;      
	
}
};
