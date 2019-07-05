// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#define deb(x) cerr << x << endl;
#define pb push_back
using namespace std;
void bfs(map<int, vector<int>>& graph, vector<bool> visited, int query_vertex, int query_level)
{
	queue<int> myqueue;
	myqueue.push(query_vertex);
	vector<int> levels(visited.size() + 1, 0);
	visited[query_vertex] = true;
	while(!myqueue.empty())
	{
		int parent = myqueue.front();
		myqueue.pop();
		for (int connected: graph[parent])
		{
			if (!visited[connected])
			{
				visited[connected] = true;
				myqueue.push(connected);
				levels[connected] = levels[parent] + 1;
			}
		}	
	}
	int ans = 0;
	for (int i = 0; i < int(levels.size()); ++i)
		ans += (query_level == levels[i]);
	cout <<  ans << endl;
}
int main()
{
	int no_of_vertices, no_of_edges;
	cin >> no_of_vertices >> no_of_edges;
	map<int, vector<int>> graph;
	for (int i = 0; i < no_of_edges; ++i)
	{
		int u, v;
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	vector<bool> visited(no_of_vertices + 1, false);
	int no_of_queries;
	cin >> no_of_queries;
	for (int i = 0; i < no_of_queries; ++i)
	{
		int query_vertex, query_level;
		cin >> query_vertex >> query_level;
		bfs(graph, visited, query_vertex, query_level);
	}
	return 0;
}
