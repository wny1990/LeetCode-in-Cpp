/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
	queue<UndirectedGraphNode*> q;
	unordered_map<int,UndirectedGraphNode*>  node_map;
	if (node == NULL)
		return NULL;
	q.push(node);
	UndirectedGraphNode* node0 = new UndirectedGraphNode(node->label);
	node_map.insert({node->label,node0});
	while(q.size())
	{
		UndirectedGraphNode* node1 = q.front();
		q.pop();
		auto father = node_map.find(node1->label);
		for ( int i = 0; i < (*node1).neighbors.size(); i++)
		{
			UndirectedGraphNode* son = (*node1).neighbors.at(i);
			auto it = node_map.find(son->label);
			if (it != node_map.end())
			{
				father->second->neighbors.push_back(it->second);
			}
			else
			{
				UndirectedGraphNode* son1 = new UndirectedGraphNode(son->label);
				node_map.insert({son->label,son1});
				father->second->neighbors.push_back(son1);
				q.push(son);
			}
				
		}
		
	}
	return node0;
}
};
