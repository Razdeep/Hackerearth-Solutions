// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define pb push_back
using namespace std;
void bfs(map<int, vector<int>>& graph, vector<int>& visited, int source)
{
	queue<int> myqueue;
	myqueue.push(source);
	visited[source] = true;
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
			}
		}
	}
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
	int source;
	cin >> source;
	vector<int> visited(no_of_vertices + 1, false);
	bfs(graph, visited, source);
	int ans = 0;
	for (int i = 1; i <= no_of_vertices; ++i)
		ans += (visited[i] == false);
	cout << ans << endl;
	return 0;
}
