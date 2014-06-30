class Solution {
public:
void probe( vector<int> vec, vector<int> source )
{
    int i;
	if (source.size() == 1)
	{
		vec.push_back(source.at(0));
		result.push_back(vec);
		return;
	}
	for(i = 0; i < source.size(); i++)
	{
		if ( i !=0 && source.at(i) == source.at(i-1))
			continue;
		vector<int> neo_source;
		vector<int> neo_vec;
		neo_source = source;
		neo_vec = vec;
		neo_vec.push_back(neo_source.at(i));
		neo_source.erase(neo_source.begin() + i);
		probe(neo_vec, neo_source);

	}
	return;

}

vector<vector<int> > permuteUnique(vector<int> &num) 
{
	sort(num.begin(),num.end());
	vector<int>  vec;
	probe(vec,num); 
	return result;
}

private:
	vector<vector<int> >  result;    
};
