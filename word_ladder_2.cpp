class Solution {
public:
int bfs(string start, string end, unordered_set<string> &dict, unordered_map<string,int> &level) 
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
			q = q1;
			q1 = queue<string>();
		}
		string str = q.front();
		q.pop();
		if (str == end)
			return dist;
		for ( int i = 0; i < str.size(); i++)
			for ( char c = 'a'; c <= 'z'; c++)
			{
				if (str[i] == c) continue;
				string str1 = str;
				str1[i] = c;
				if ( dict.find(str1) != dict.end() && !level.count(str1))
				{
					q1.push(str1);
					level[str] = dist;
				}

			}	
	}
	return 0;
}

void find(string &str,string &end, unordered_map<string,int> &level, int dist,vector<string> &vec)
{
	if ( dist > min + 1)
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
			if ( level.count(str1)  && level[str1] == level[str] + 1)
			{
				vec.push_back(str1);
				find(str1,end,level,dist + 1,vec);
			        vec.pop_back();
			}
		}
	return;
}
vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
{
	int n = dict.size();
	unordered_map<string,int> level;
	min = bfs(start,end,dict,level);
	vector<string> vec;
	vec.push_back(start);
	find(start,end,level,0,vec);
	return result;
}
private:
	vector<vector<string>> result;
	int min;
};
