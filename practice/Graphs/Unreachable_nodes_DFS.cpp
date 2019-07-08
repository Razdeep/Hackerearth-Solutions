/**
 * ---------------------------
 *  DFS on graph using stacks
 * ---------------------------
 * @author: Rajdeep Roy Chowdhury <rrajdeeproychowdhury@gmail.com>
 *
 * https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/
 *
 *
 */
#include <iostream>
#include <vector>
#include <stack>
#include <map>
#define pb push_back
using namespace std;
void dfs(map<int, vector<int>> graph, vector<bool>& visited, int source)
{
	stack<int> mystack;
	mystack.push(source);
	visited[source] = true;
	while(!mystack.empty())
	{
		int parent = mystack.top();
		mystack.pop();
		for (int connected: graph[parent])
		{
			if (!visited[connected])
			{
				visited[connected] = true;
				mystack.push(connected);
			}	
		}
	}
}
int main()
{
	int no_of_vertices, no_of_edges;
	cin >> no_of_vertices >> no_of_edges;
	map<int, vector<int>> graph;
	vector<bool> visited(no_of_vertices + 1, false);
	for (int i = 0; i < no_of_edges; ++i)
	{
		int u, v;
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	int source;
	cin >> source;
	dfs(graph, visited, source);
	int ans = 0;
	for (int i = 1; i <= no_of_vertices; ++i)
		ans += (visited[i] == false);
	cout << ans << endl;
}
