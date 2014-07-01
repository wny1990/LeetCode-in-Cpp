class Solution {
public:
int ladderLength(string start, string end, unordered_set<string> &dict) 
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
};
