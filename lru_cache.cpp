class LRUCache{
public:
LRUCache(int capacity) 
{
       	cap = capacity;
}
    
int get(int key)
{
	if(!addr.count(key))
		return - 1;
	auto it = addr[key];
	int value = it->second;
	q.erase(it);
	q.push_front({key,value});
	auto it1 = addr.find(key);
	addr.erase(it1);
        addr.insert({key,q.begin()});
	return value;
}
  

void set(int key, int value)
{
	if (addr.count(key))
	{
		list<pair<int,int> >::iterator it = addr[key];
		q.erase(it);
		auto it1 = addr.find(key);
		addr.erase(it1);
	}

	if( addr.size() == cap )
	{
		int k = q.back().first;
		auto it1 = addr.find(k);
		addr.erase(it1);
		q.pop_back();
	}
	q.push_front({key,value});
        addr.insert({key,q.begin()});
}

private:
	int cap;
	list<pair<int,int>> q;
	unordered_map<int, list<pair<int,int> >::iterator > addr;
};
