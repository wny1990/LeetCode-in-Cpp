#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
int bfs(string start, string end, unordered_set<string> &dict, unordered_map<string,int> &level) 
{
	int n = dict.size();
	queue<string> q;
	q.push(start);
	int dist = 0;
	queue<string> q1;
	level[start] = 0;
	while(q.size() || q1.size())
	{
		if (q.size() == 0)
		{
			dist++;
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
				if ( (dict.count(str1) || str1 == end ) && !level.count(str1))
				{
					q1.push(str1);
					level[str1] = dist + 1;
				}

			}	
	}
	return 0;
}

void find(string &str,string &end, unordered_map<string,int> &level,  unordered_map<string,int> &level1, int dist,vector<string> &vec)
{
	if ( dist > min )
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
			if (  level.count(str1) && level1.count(str1) && level[str1] == level[str] + 1 && level1[str] == level1[str1] + 1)
			{
				vec.push_back(str1);
				find(str1,end,level,level1,dist + 1,vec);
			        vec.pop_back();
			}
		}
	return;
}
vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
{
	int n = dict.size();
	unordered_map<string,int> level;
	unordered_map<string,int> level1;
	min = bfs(start,end,dict,level);
	bfs(end,start,dict,level1);
	vector<string> vec;
	vec.push_back(start);
	find(start,end,level,level1,0,vec);
	return result;
}
private:
	vector<vector<string>> result;
	int min;
};
int main()
{
	Solution sol; 
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	vector<vector<string>> result = sol.findLadders("hit","cog",dict);
	for ( int i = 0; i < result.size();i++)
	{
		for( int j =0; j< result.at(i).size();j++)
			cout << result[i][j] <<"  ";
		cout << endl;
	}
}
