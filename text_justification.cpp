class Solution {
public:
vector<string> fullJustify(vector<string> &words, int L) 
{
       
	vector<string> result;
	vector<string> temp;
	int size = 0;
	if ( words.size() == 0 ||  words[0].size() == 0)
	{
		string rt(L,' ');
		result.push_back(rt);
		return result;
	}
	for( int i = 0; i < words.size();i++)
	{
		if (words[i].size() == 0)
			continue;
		if ( (size && size  + 1 + words[i].size() > L)|| (!size && words[i].size() > L ) )
		{
			string row;
			int spaces ;
			if (temp.size() == 1)
				spaces  = 0;
			else
				spaces = (L - size)/(temp.size() - 1);
			int remain = L - size -spaces*(temp.size() - 1);
			string str_spaces(spaces,' ');
			for( int j =0; j < temp.size(); j++)
			{
				if (j)
				{
					row.append(" ");
					row.append(str_spaces);
					if (remain)
					{
						row.append(" ");
						remain--;
					}
					}
				row.append(temp[j]);
			}
			if ( temp.size() == 1)
				row.append(string(remain,' '));
			result.push_back(row);
			temp.clear();
			size = 0;
			i--;
		}
		else
		{
			if (size)
				size++;
			size+= words[i].size();
			temp.push_back(words[i]);
		}

	}
	if (temp.size())
	{
			string row;
			int remain = L - size;
			for( int j =0; j < temp.size(); j++)
			{
				if (j)
					row.append(" ");
				row.append(temp[j]);
			}
			row.append(string(remain,' '));
			result.push_back(row);
			temp.clear();
			size = 0;
	}

	return result;
}
};
