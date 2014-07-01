class Solution {
public:
int ladderLength(string start, string end, unordered_set<string> dict) 
{
	int n = dict.size();
	queue<string> q;
	q.push(start);
	int dist = 0;
	queue<string> q1;
	while(q.size() || q1.size())
	{
		if (q.size() == 0)
		{
			dist ++;
			if (dist > n + 1)
				return 0;
			q = q1;
			q1 = queue<string>();
		}
		string str = q.front();
		q.pop();
		if (str == end) return dist + 1;
		for ( int i = 0; i < str.size(); i++)
			for ( char c = 'a'; c <= 'z'; c++)
			{
				if (str[i] == c) continue;
				string str1 = str;
				str1[i] = c;
				if ( dict.find(str1) != dict.end())
				{
					q1.push(str1);
					dict.erase(str1);
				}

			}	
	}
	return 0;
}

void find(string &str,string &end, unordered_set<string> &dict, int dist,vector<string> &vec)
{
	if ( dist > min_dist )
		return;
	if (str == end)
	{
		result.push_back(vec);
		return;
	}
	for ( int i = 0; i < str.size(); i++)
		for ( char c = 'a'; c <= 'z'; c++)
		{
			if (str[i] == c) continue;
			string str1 = str;
			str1[i] = c;
			if ( dict.find(str1) != dict.end() )
			{
				dict.erase(str1);
				vec.push_back(str1);
				find(str1,end,dict,dist + 1,vec);
			        vec.pop_back();
				dict.insert(str1);
			}
		}
	return;
}
vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
{
	int n = dict.size();
	min_dist = ladderLength(start,end,dict);
	vector<string> vec;
	vec.push_back(start);
	find(start,end,dict,0,vec);
	return result;
}
private:
	vector<vector<string>> result;
	int min_dist;
};
