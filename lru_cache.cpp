#include<iostream>
#include<deque>
#include<map>
using namespace std;

class LRUCache{
public:
LRUCache(int capacity) 
{
       	cap = capacity;
}
    
int get(int key)
{
	auto it = addr.find(key);
	if (it == addr.end())
		return -1;
	int value = (*it).second;
	q.earse(it);
	q.push_back({key,value});
	return value;

}
    
void set(int key, int value)
{
	auto it = addr.find(key);
	if (it != addr.end())
		addr.earse(it);
	if( q.size() == cap )
	{
		int k = q.front().first;
		auto it1 = addr.find(k);
		addr.earse(it1);
		q.pop_front();
	}
	q.push_back({key,value});
        addr.insert({key,q.end() - 1});
}
private:
	int cap;
	deque<int,int> q;
	map<int, deque<int,int>::iterator > addr;
};
